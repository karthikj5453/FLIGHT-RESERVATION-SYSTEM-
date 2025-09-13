#include <iostream>
#include <string>
using namespace std;
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
    Booking(int id = 0, string fdet = "", string pdet = "", string seat = "", string pay = "")
    {
        Booking_ID = id;
        flight_details = fdet;
        passenger_details = pdet;
        Seat_No = seat;
        Payment_Info = pay;
        Status = "Pending";
    }
    ~Booking() {}
    void set_booking_details()
    {
        cout << "Enter Booking ID: ";
        cin >> Booking_ID;
        cin.ignore();
        cout << "Enter Flight Details: ";
        getline(cin, flight_details);
        cout << "Enter Passenger Details: ";
        getline(cin, passenger_details);
        cout << "Enter Seat Number: ";
        getline(cin, Seat_No);
        cout << "Enter Payment Information: ";
        getline(cin, Payment_Info);
        Status = "Pending";
    }
    void confirm_booking()
    {
        if (Status == "Cancelled")
        {
            cout << "Booking " << Booking_ID << " was cancelled. Cannot confirm." << endl;
        }
        else
        {
            Status = "Confirmed";
            cout << "Booking " << Booking_ID << " is now confirmed." << endl;
        }
    }
    void cancel_booking()
    {
        if (Status == "Cancelled")
        {
            cout << "Booking " << Booking_ID << " is already cancelled." << endl;
        }
        else
        {
            Status = "Cancelled";
            cout << "Booking " << Booking_ID << " has been cancelled." << endl;
        }
    }
    void change_seat()
    {
        if (Status != "Confirmed")
        {
            cout << "Booking " << Booking_ID << " is not confirmed yet. Cannot change seat." << endl;
        }
        else
        {
            string new_seat;
            cout << "Enter new seat number: ";
            cin.ignore();
            getline(cin, new_seat);
            cout << "Seat changed from " << Seat_No << " to " << new_seat
                 << " for booking " << Booking_ID << "." << endl;
            Seat_No = new_seat;
        }
    }
    void Show_Booking()
    {
        cout << "\n--- Booking Details ---\n";
        cout << "Booking ID: " << Booking_ID << endl;
        cout << "Flight Details: " << flight_details << endl;
        cout << "Passenger Details: " << passenger_details << endl;
        cout << "Seat Number: " << Seat_No << endl;
        cout << "Booking Status: " << Status << endl;
        cout << "Payment Information: " << Payment_Info << endl;
    }
};

int main()
{
    Booking booking1;
    booking1.set_booking_details();
    booking1.Show_Booking();
    booking1.confirm_booking();
    booking1.change_seat();
    booking1.cancel_booking();
    booking1.Show_Booking();
    return 0;
}
