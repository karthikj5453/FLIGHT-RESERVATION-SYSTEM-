#include <bits/stdc++.h>
using namespace std;
class Flight
{
    static int booked_seats;
    void update_price(string);
public:
    int flight_number, origin, dest, departure_time,
        arrival_time, total_seats, aircraft_type;
    map<string, int> seat_classes;
    Flight();
    void show_classes();
    void check_availibility();
    void cancel_seat(string);
};
int Flight::booked_seats = 0;
Flight::Flight()
{
    seat_classes["Business"] = 20;
    seat_classes["Economy"] = 50;
    seat_classes["Premium"] = 30;
    total_seats = 100;
}
void Flight::show_classes()
{
    cout << "\nAvailable seat classes:\n";
    for (auto &c : seat_classes)
    {
        cout << " - " << c.first << " : " << c.second << " seats available\n";
    }
}
void Flight::update_price(string cls)
{
    int total = 0;
    if (cls == "Business")
        total = 20;
    if (cls == "Economy")
        total = 50;
    if (cls == "Premium")
        total = 30;
    int available = seat_classes[cls];
    double occupancy = (double)(total - available) / total;
    int basePrice;
    if (cls == "Business")
        basePrice = 5000;
    if (cls == "Economy")
        basePrice = 3000;
    if (cls == "Premium")
        basePrice = 4500;
    int price = basePrice + (int)(basePrice * occupancy * 0.5);
    cout << "Updated price for " << cls << " class: ₹" << price << endl;
}
void Flight::check_availibility()
{
    cout << "\nChecking seat availability...\n";
    show_classes();
    string choice;
    cout << "\nEnter the class you want to book (e.g., Business, Economy or Premium): ";
    cin >> choice;
    if (seat_classes.find(choice) == seat_classes.end())
    {
        cout << "Invalid class chosen.\n";
        return;
    }
    if (seat_classes[choice] <= 0)
    {
        cout << "Sorry, no seats available in " << choice << " class.\n";
        return;
    }
    char ch;
    cout << "Do you want to confirm your booked seat in " << choice << "? [Y/N]: ";
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
    {
        seat_classes[choice]--;
        cout << "Seat confirmed in " << choice << " class.\n"
             << "Redirecting to payment gateway...\n";
    }
    else
    {
        cout << "Thanks for visiting our platform.\n";
    }
}
void Flight::cancel_seat(string choice)
{
    if (seat_classes.find(choice) != seat_classes.end())
    {
        seat_classes[choice]++;
        cout << "Seat in " << choice << " class has been cancelled.\n";
    }
    else
    {
        cout << "Invalid class.\n";
    }
}