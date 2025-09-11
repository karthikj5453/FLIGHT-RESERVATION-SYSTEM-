#include <bits/stdc++.h>
using namespace std;

class Flight
{
    static int booked_seats;

public:
    int flight_number, origin, dest, departure_time,
        arrival_time, total_seats;
    map<string, int> seat_classes;
    string booked_class; 
    void update_price(string);
    Flight();
    void show_classes();
    void check_availibility();
    void cancel_seat();
};

int Flight::booked_seats = 0;

Flight::Flight()
{
    seat_classes["Business"] = 20;
    seat_classes["Economy"] = 50;
    seat_classes["Premium"] = 30;
    total_seats = 100;
    booked_class = "";
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
        booked_class = choice;
        cout << "Seat confirmed in " << choice << " class.\n"
             << "Redirecting to payment gateway...\n";
    }
    else
    {
        cout << "Booking cancelled.\n";
    }
}

void Flight::cancel_seat()
{
    if (booked_class == "")
    {
        cout << "You don’t have any active booking to cancel.\n";
        return;
    }

    seat_classes[booked_class]++;
    cout << "Your seat in " << booked_class << " class has been cancelled.\n";
    booked_class = "";
}

int main()
{
    Flight *f1 = new Flight();
    int choice;
    do
    {
        cout << "\n----- FLIGHT RESERVATION MENU -----\n";
        cout << "1. Show Available Classes\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel My Seat\n";
        cout << "4. Check Updated Price\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            f1->show_classes();
            break;
        }
        else if (choice == 2)
        {
            f1->check_availibility();
            break;
        }
        else if (choice == 3)
        {
            f1->cancel_seat();
            break;
        }
        else if (choice == 4)
        {
            string cls;
            cout << "Enter class name (Business/Economy/Premium): ";
            cin >> cls;
            f1->update_price(cls);
            break;
        }
        else if (choice == 5)
        {
            cout << "Exiting... Thank you!\n";
            break;
        }
        else
        {
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 5);
    delete f1;
    return 0;
}
