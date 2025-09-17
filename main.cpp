#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Passenger
{
    int id;
    string name, contact, gmail;
    int age;

public:
    Passenger(int i = 0, string n = "Unknown", string c = "N/A", string g = "N/A", int a = 0)
        : id(i), name(n), contact(c), gmail(g), age(a) {}
    int getID() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
    void display() { cout << id << " | " << name << " | " << age << " | " << contact << " | " << gmail << endl; }
    void saveToFile()
    {
        ofstream fout("passengers.csv", ios::app);
        fout << id << "," << name << "," << age << "," << contact << "," << gmail << "\n";
    }
    static Passenger *getPassengerByID(int pid)
    {
        ifstream fin("passengers.csv");
        string line;
        int id, age;
        string name, contact, gmail;
        while (getline(fin, line))
        {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            id = stoi(token);
            getline(ss, name, ',');
            getline(ss, token, ',');
            age = stoi(token);
            getline(ss, contact, ',');
            getline(ss, gmail, ',');
            if (id == pid)
                return new Passenger(id, name, contact, gmail, age);
        }
        return nullptr;
    }
};

class Flight
{
    int flightNo;
    string from, to, depTime, arrTime;
    int capacityE, capacityB, capacityF;
    int bookedE, bookedB, bookedF;

public:
    Flight(int fn = 0, string f = "NA", string t = "NA", string dep = "00:00", string arr = "00:00", int ce = 100, int cb = 50, int cf = 10)
        : flightNo(fn), from(f), to(t), depTime(dep), arrTime(arr), capacityE(ce), capacityB(cb), capacityF(cf), bookedE(0), bookedB(0), bookedF(0) {}
    int getFlightNo() { return flightNo; }
    string getFrom() { return from; }
    string getTo() { return to; }
    bool bookSeat(string cls, int num)
    {
        if (cls == "E" && bookedE + num <= capacityE)
        {
            bookedE += num;
            return true;
        }
        if (cls == "B" && bookedB + num <= capacityB)
        {
            bookedB += num;
            return true;
        }
        if (cls == "F" && bookedF + num <= capacityF)
        {
            bookedF += num;
            return true;
        }
        return false;
    }
    bool cancelSeat(string cls, int num)
    {
        if (cls == "E" && bookedE - num >= 0)
        {
            bookedE -= num;
            return true;
        }
        if (cls == "B" && bookedB - num >= 0)
        {
            bookedB -= num;
            return true;
        }
        if (cls == "F" && bookedF - num >= 0)
        {
            bookedF -= num;
            return true;
        }
        return false;
    }
    void display() { cout << flightNo << " | " << from << " -> " << to << " | " << depTime << " - " << arrTime << "\nE: " << bookedE << "/" << capacityE << " B: " << bookedB << "/" << capacityB << " F: " << bookedF << "/" << capacityF << endl; }
    void updateFile()
    {
        vector<string> lines;
        ifstream fin("flights.csv");
        string line;
        while (getline(fin, line))
        {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            int fn = stoi(token);
            if (fn == flightNo)
                line = to_string(flightNo) + "," + from + "," + to + "," + depTime + "," + arrTime + "," + to_string(capacityE) + "," + to_string(capacityB) + "," + to_string(capacityF) + "," + to_string(bookedE) + "," + to_string(bookedB) + "," + to_string(bookedF);
            lines.push_back(line);
        }
        fin.close();
        ofstream fout("flights.csv");
        for (auto &l : lines)
            fout << l << "\n";
    }
    static vector<Flight *> loadFlights()
    {
        vector<Flight *> flights;
        ifstream fin("flights.csv");
        string line;
        while (getline(fin, line))
        {
            stringstream ss(line);
            string token;
            int fn, ce, cb, cf, be, bb, bf;
            string from, to, dep, arr;
            getline(ss, token, ',');
            fn = stoi(token);
            getline(ss, from, ',');
            getline(ss, to, ',');
            getline(ss, dep, ',');
            getline(ss, arr, ',');
            getline(ss, token, ',');
            ce = stoi(token);
            getline(ss, token, ',');
            cb = stoi(token);
            getline(ss, token, ',');
            cf = stoi(token);
            getline(ss, token, ',');
            be = stoi(token);
            getline(ss, token, ',');
            bb = stoi(token);
            getline(ss, token, ',');
            bf = stoi(token);
            Flight *f = new Flight(fn, from, to, dep, arr, ce, cb, cf);
            f->bookedE = be;
            f->bookedB = bb;
            f->bookedF = bf;
            flights.push_back(f);
        }
        return flights;
    }
};

class Booking
{
    string pnr;
    Passenger *mainP;
    Flight *flight;
    string cls;
    int seats;
    vector<pair<string, int>> companions;

public:
    Booking(string p = "", Passenger *psg = nullptr, Flight *f = nullptr, string c = "E", int s = 1) : pnr(p), mainP(psg), flight(f), cls(c), seats(s) {}
    void addCompanion(string n, int a) { companions.push_back({n, a}); }
    void display()
    {
        cout << "PNR: " << pnr << " | Class: " << cls << " | Seats: " << seats << "\nMain Passenger:\n";
        mainP->display();
        if (!companions.empty())
        {
            cout << "Companions:\n";
            for (auto &x : companions)
                cout << x.first << " | " << x.second << endl;
        }
        flight->display();
    }
    void saveToFile()
    {
        ofstream fout("bookings.csv", ios::app);
        fout << pnr << "," << mainP->getID() << "," << flight->getFlightNo() << "," << cls << "," << seats;
        for (auto &x : companions)
            fout << "," << x.first << ":" << x.second;
        fout << "\n";
    }
    static string generatePNR()
    {
        string s = "PNR";
        for (int i = 0; i < 6; i++)
            s += char('A' + rng() % 26);
        for (int i = 0; i < 3; i++)
            s += char('0' + rng() % 10);
        return s;
    }
};

void pressEnter()
{
    cout << "\nPress ENTER...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
bool validIntInput(int &n)
{
    cin >> n;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

int main()
{
    vector<Flight *> flights = Flight::loadFlights();
    int choice;
    do
    {
        cout << "\n===== Airline Menu =====\n";
        cout << "1. Add Passenger\n";
        cout << "2. Show Passenger\n";
        cout << "3. Book Flight\n";
        cout << "4. Cancel Booking\n";
        cout << "5. Show Bookings\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        if (!validIntInput(choice))
        {
            cout << "Invalid choice!\n";
            pressEnter();
            continue;
        }

        if (choice == 1)
        {
            int id, age;
            string name, contact, gmail;
            cout << "Enter ID: ";
            if (!validIntInput(id))
            {
                pressEnter();
                continue;
            }
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            if (!validIntInput(age))
            {
                pressEnter();
                continue;
            }
            cout << "Enter Contact: ";
            cin >> contact;
            cout << "Enter Gmail: ";
            cin >> gmail;
            Passenger *p = new Passenger(id, name, contact, gmail, age);
            p->saveToFile();
            delete p;
            cout << "Passenger added.\n";
            pressEnter();
        }
        else if (choice == 2)
        {
            ifstream fin("passengers.csv");
            string line;
            cout << "Passengers:\n";
            while (getline(fin, line))
                cout << line << endl;
            fin.close();
            pressEnter();
        }
        else if (choice == 3)
        {
            int pid, numComp;
            cout << "Passenger ID: ";
            if (!validIntInput(pid))
            {
                pressEnter();
                continue;
            }
            Passenger *p = Passenger::getPassengerByID(pid);
            if (!p)
            {
                cout << "Passenger not found\n";
                pressEnter();
                continue;
            }
            string src, dest, cls;
            int seats;
            cout << "Enter Source and Destination: ";
            cin >> src >> dest;
            vector<Flight *> avail;
            for (auto f : flights)
                if (f->getFrom() == src && f->getTo() == dest)
                    avail.push_back(f);
            if (avail.empty())
            {
                cout << "No flights available\n";
                delete p;
                pressEnter();
                continue;
            }
            cout << "Available flights:\n";
            for (auto f : avail)
                f->display();
            int fn;
            cout << "Select Flight No: ";
            if (!validIntInput(fn))
            {
                delete p;
                pressEnter();
                continue;
            }
            Flight *fsel = nullptr;
            for (auto f : avail)
                if (f->getFlightNo() == fn)
                    fsel = f;
            if (!fsel)
            {
                cout << "Invalid flight\n";
                delete p;
                pressEnter();
                continue;
            }
            cout << "Enter Class(E/B/F) and number of seats: ";
            cin >> cls >> seats;
            if (!fsel->bookSeat(cls, seats))
            {
                cout << "Not enough seats\n";
                delete p;
                pressEnter();
                continue;
            }
            Booking *b = new Booking(Booking::generatePNR(), p, fsel, cls, seats);
            cout << "Enter number of companions (excluding minors): ";
            if (!validIntInput(numComp))
            {
                delete b;
                delete p;
                pressEnter();
                continue;
            }
            for (int i = 0; i < numComp; i++)
            {
                string n;
                int a;
                cout << "Companion Name and Age: ";
                cin >> n >> a;
                b->addCompanion(n, a);
            }
            b->saveToFile();
            fsel->updateFile();
            delete b;
            delete p;
            pressEnter();
        }
        else if (choice == 4)
        {
            string pnr;
            cout << "Enter PNR to cancel: ";
            cin >> pnr;
            ifstream fin("bookings.csv");
            vector<string> lines;
            string line;
            bool found = false;
            while (getline(fin, line))
            {
                stringstream ss(line);
                string token;
                getline(ss, token, ',');
                if (token == pnr)
                {
                    found = true;
                    continue;
                }
                lines.push_back(line);
            }
            fin.close();
            if (!found)
            {
                cout << "PNR not found\n";
                pressEnter();
                continue;
            }
            ofstream fout("bookings.csv");
            for (auto &l : lines)
                fout << l << "\n";
            fout.close();
            cout << "Booking cancelled.\n";
            pressEnter();
        }
        else if (choice == 5)
        {
            ifstream fin("bookings.csv");
            string line;
            cout << "Bookings:\n";
            while (getline(fin, line))
                cout << line << endl;
            fin.close();
            pressEnter();
        }
    } while (choice != 0);
    for (auto f : flights)
        delete f;
}
