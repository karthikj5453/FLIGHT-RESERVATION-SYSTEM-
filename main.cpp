#include <bits/stdc++.h>
using namespace std;
class Passenger
{
private:
    int passenger_ID;
    string name;
    string contact_info;
    string passport_details;
public:
    Passenger(int id = 0, string n = "", string contact = "", string passport = "")
    {
        passenger_ID = id;
        name = n;
        contact_info = contact;
        passport_details = passport;
    }
    ~Passenger() {}
    void setdata(int id, string n, string contact, string passport)
    {
        passenger_ID = id;
        name = n;
        contact_info = contact;
        passport_details = passport;
    }
    void update_contact_info(string new_contact)
    {
        contact_info = new_contact;
    }
    string getDetails()
    {
        return "Passenger ID: " + to_string(passenger_ID) + ", Name: " + name;
    }
    void display()
    {
        cout << "Passenger ID: " << passenger_ID
             << " -> Name: " << name
             << " -> Contact: " << contact_info
             << " -> Passport: " << passport_details << endl;
    }
};
class Booking
{
private:
    int Booking_ID;
    string flight_details;
    string passenger_details;
    string Seat_No;
    string Status;
    string Payment_Info;

public:
    Booking(int id = 0)
    {
        Booking_ID = id;
        Status = "Pending";
    }
    ~Booking(){}
    void set_bking_details(string flight, string passenger, string seat, string payment)
    {
        flight_details = flight;
        passenger_details = passenger;
        Seat_No = seat;
        Payment_Info = payment;
    }
    void confirm_booking()
    {
        if (Status == "Cancelled")
            cout << "Booking " << Booking_ID << " was cancelled. Cannot confirm.\n";
        else
        {
            Status = "Confirmed";
            cout << "Booking " << Booking_ID << " confirmed.\n";
        }
    }
    void cancel_booking()
    {
        if (Status == "Cancelled")
            cout << "Booking " << Booking_ID << " is already cancelled.\n";
        else
        {
            Status = "Cancelled";
            cout << "Booking " << Booking_ID << " cancelled.\n";
        }
    }
    void change_seat(string new_seat)
    {
        if (Status != "Confirmed")
            cout << "Booking " << Booking_ID << " is not confirmed yet. Cannot change seat.\n";
        else
        {
            cout << "Seat changed from " << Seat_No << " to " << new_seat << " for booking " << Booking_ID << ".\n";
            Seat_No = new_seat;
        }
    }
    void display_booking()
    {
        cout << "\n--- Booking Details ---\n";
        cout << "-> Booking ID: " << Booking_ID << endl;
        cout << "-> Flight Details: " << flight_details << endl;
        cout << "-> Passenger Details: " << passenger_details << endl;
        cout << "-> Seat Number: " << Seat_No << endl;
        cout << "-> Booking Status: " << Status << endl;
        cout << "-> Payment Information: " << Payment_Info << endl;
    }
};
class Flight
{
    static int booked_seats;

public:
    int flight_number, total_seats;
    map<string, int> seat_classes;
    string booked_class;
    Flight(int number = 101)
    {
        flight_number = number;
        seat_classes["Business"] = 20;
        seat_classes["Economy"] = 50;
        seat_classes["Premium"] = 30;
        total_seats = 100;
        booked_class = "";
        cout << "Flight " << flight_number << " created.\n";
    }
    ~Flight() {}
    void show_classes()
    {
        cout << "\nAvailable seat classes in Flight " << flight_number << ":\n";
        for (auto &c : seat_classes)
            cout << " - " << c.first << " : " << c.second << " seats available\n";
    }
    void update_price(string cls)
    {
        int total = seat_classes[cls];
        int available = seat_classes[cls];
        double occupancy = (double)(total - available) / total;
        int basePrice = (cls == "Business") ? 5000 : (cls == "Economy" ? 3000 : 4500);
        int price = basePrice + (int)(basePrice * occupancy * 0.5);
        cout << "Updated price for " << cls << " class: ₹" << price << endl;
    }
    bool book_seat(string cls)
    {
        if (seat_classes.find(cls) == seat_classes.end() || seat_classes[cls] <= 0)
        {
            cout << "Sorry, no seats available in " << cls << ".\n";
            return false;
        }
        seat_classes[cls]--;
        booked_class = cls;
        cout << "Seat booked in " << cls << " class of Flight " << flight_number << ".\n";
        return true;
    }
    void cancel_seat()
    {
        if (booked_class == "")
        {
            cout << "No booking to cancel.\n";
            return;
        }
        seat_classes[booked_class]++;
        cout << "Seat in " << booked_class << " class cancelled.\n";
        booked_class = "";
    }
};
int Flight::booked_seats = 0;
class Aircrafts
{
private:
    string manufacturer;
    string model;
    map<string, int> cabinCapacity;
    int totalseats;

public:
    Aircrafts(string manu = "Unknown", string mo = "Unknown")
    {
        manufacturer = manu;
        model = mo;
        totalseats = 0;
        cout << "Aircraft (" << manufacturer << " " << model << ") created.\n";
    }
    ~Aircrafts() {}
    void addCabin(string cabinClass, int capacity)
    {
        cabinCapacity[cabinClass] = capacity;
    }
    int gettotalCapacity()
    {
        totalseats = 0;
        for (auto &c : cabinCapacity)
            totalseats += c.second;
        return totalseats;
    }
    void display_SeatCategories()
    {
        cout << "\nCabin Categories of " << manufacturer << " " << model << ":\n";
        for (auto &a : cabinCapacity)
        {
            cout << " - " << a.first << " : " << a.second << " seats\n";
        }
    }
};
int main()
{
    cout << "\n===== AIRLINE MANAGEMENT DEMO SYSTEM =====\n";
    Passenger p1(1, "Karthik", "777777777", "CR7");
    p1.display();
    p1.update_contact_info("999999999");
    cout << "After contact update:\n";
    p1.display();
    Flight f1(501);
    f1.show_classes();
    f1.book_seat("Economy");
    f1.update_price("Economy");
    Aircrafts a1("Emirates Airways", "A380");
    a1.addCabin("Economy", 150);
    a1.addCabin("Business", 30);
    a1.display_SeatCategories();
    cout << "Total Capacity: " << a1.gettotalCapacity() << endl;
    Booking b1(1001);
    b1.set_bking_details("Emirates", p1.getDetails(), "12A", "Paid via Credit Card");
    b1.confirm_booking();
    b1.change_seat("14A");
    b1.display_booking();
    b1.cancel_booking();
    return 0;
}
