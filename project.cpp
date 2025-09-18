#include <iostream>
#include <vector>
using namespace std;

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

    void display()
    {
        cout << id << " | " << name << " | " << age << " | " << contact << " | " << gmail << endl;
    }

    void saveToFile()
    {
        ofstream fout("passengers.csv", ios::app);
        fout << id << "," << name << "," << age << "," << contact << "," << gmail << "\n";
    }

    static Passenger *getPassengerByID(int pid)  //todo: returns a pointer to a passenger object

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

    friend void updatePassengerInfo(Passenger &p);
};

void updatePassengerInfo(Passenger &p)
{
    string input;
    int age;

    cin.ignore();
    cout << "Enter new Name (current: " << p.name << "): ";
    getline(cin, input);
    if (!input.empty())
        p.name = input;

    cout << "Enter new Age (current: " << p.age << "): ";
    cin >> age;
    if (age > 0)
        p.age = age;

    cin.ignore();
    cout << "Enter new Contact (current: " << p.contact << "): ";
    getline(cin, input);
    if (!input.empty())
        p.contact = input;

    cout << "Enter new Gmail (current: " << p.gmail << "): ";
    getline(cin, input);
    if (!input.empty())
        p.gmail = input;

    vector<string> lines;
    ifstream fin("passengers.csv");
    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        if (stoi(token) == p.id)
            line = to_string(p.id) + "," + p.name + "," + to_string(p.age) + "," + p.contact + "," + p.gmail;
        lines.push_back(line);
    }
    fin.close();
    ofstream fout("passengers.csv");
    for (auto &l : lines)
        fout << l << "\n";
    fout.close();
    cout << "Passenger info updated successfully!\n";
}
