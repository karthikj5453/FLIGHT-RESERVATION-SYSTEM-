#include <bits/stdc++.h>
using namespace std;

class Passenger
{
    int id;
    string name;
    string contact;

public:
    Passenger(int i = 0, string n = "Unknown", string c = "N/A")
    {
        id = i;
        name = n;
        contact = c;
    }
    ~Passenger() {}
    void setData(int i, string n, string c)
    {
        id = i;
        name = n;
        contact = c;
    }
    void display()
    {
        cout << "Passenger ID: " << id
             << " | Name: " << name
             << " | Contact: " << contact << endl;
    }
    friend void updateContact(Passenger &p, string newc);
    string getName() { return name; }
};

void updateContact(Passenger &p, string newc)
{
    p.contact = newc;
}

class Flight
{
    int flightNo;
    int capacity;
    int booked;

public:
    Flight(int f = 0, int c = 100)
    {
        flightNo = f;
        capacity = c;
        booked = 0;
    }
    ~Flight() {}
    bool bookSeat()
    {
        if (booked < capacity)
        {
            booked++;
            return true;
        }
        return false;
    }
    void cancelSeat()
    {
        if (booked > 0)
            booked--;
    }
    void display()
    {
        cout << "Flight " << flightNo
             << " | Capacity: " << capacity
             << " | Booked: " << booked << endl;
    }
    int getNo() { return flightNo; }
};

class Booking
{
    int bookingID;
    string seat;
    Passenger *passenger;
    Flight *flight;

public:
    Booking(int id = 0, string s = "NA", Passenger *p = nullptr, Flight *f = nullptr)
    {
        bookingID = id;
        seat = s;
        passenger = p;
        flight = f;
    }
    ~Booking() {}
    void display()
    {
        cout << "Booking ID: " << bookingID
             << " | Seat: " << seat << endl;
        if (passenger)
            passenger->display();
        if (flight)
            flight->display();
    }
};

int main()
{
    Passenger *p = nullptr;
    Flight *f = nullptr;
    Booking *b = nullptr;

    int choice;
    do
    {
        cout << "\n===== Airline Menu =====\n";
        cout << "1. Add Passenger\n";
        cout << "2. Show Passenger\n";
        cout << "3. Update Passenger Contact\n";
        cout << "4. Create Flight\n";
        cout << "5. Show Flight\n";
        cout << "6. Book Seat\n";
        cout << "7. Cancel Seat\n";
        cout << "8. Show Booking\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name, contact;
            cout << "Enter ID Name Contact: ";
            cin >> id >> name >> contact;
            delete p;
            p = new Passenger(id, name, contact);
        }
        else if (choice == 2)
        {
            if (p)
                p->display();
            else
                cout << "No passenger.\n";
        }
        else if (choice == 3)
        {
            if (p)
            {
                string nc;
                cout << "Enter new contact: ";
                cin >> nc;
                updateContact(*p, nc);
            }
            else
                cout << "No passenger.\n";
        }
        else if (choice == 4)
        {
            int no, cap;
            cout << "Enter FlightNo Capacity: ";
            cin >> no >> cap;
            delete f;
            f = new Flight(no, cap);
        }
        else if (choice == 5)
        {
            if (f)
                f->display();
            else
                cout << "No flight.\n";
        }
        else if (choice == 6)
        {
            if (p && f)
            {
                if (f->bookSeat())
                {
                    int bid;
                    string seat;
                    cout << "Enter BookingID and Seat: ";
                    cin >> bid >> seat;
                    delete b;
                    b = new Booking(bid, seat, p, f);
                    cout << "Booking successful.\n";
                }
                else
                    cout << "Flight full.\n";
            }
            else
                cout << "Need passenger and flight first.\n";
        }
        else if (choice == 7)
        {
            if (f)
                f->cancelSeat();
            cout << "Seat cancelled (if any).\n";
        }
        else if (choice == 8)
        {
            if (b)
                b->display();
            else
                cout << "No booking.\n";
        }
    } while (choice != 0);

    delete p;
    delete f;
    delete b;
    return 0;
}
