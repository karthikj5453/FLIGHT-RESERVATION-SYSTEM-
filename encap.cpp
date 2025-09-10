#include <iostream>
#include <string>
using namespace std;

class Booking{
private:
    int booking_id;
    string flight_details;
    string passenger_details;
    string seat_number;
    string booking_status;
    string payment_information;

public:
    void set_booking_details(){
        cout<<"Enter Booking ID: ";
        cin>>booking_id;
        cin.ignore(); 

        cout<<"Enter Flight Details: ";
        getline(cin, flight_details);

        cout<<"Enter Passenger Details: ";
        getline(cin, passenger_details);

        cout<<"Enter Seat Number: ";
        getline(cin, seat_number);

        cout<<"Enter Payment Information: ";
        getline(cin, payment_information);

        booking_status="Pending"; 
    }

    void confirm_booking(){
        if(booking_status == "Cancelled") {
            cout << "Booking " << booking_id << " was cancelled. Cannot confirm." << endl;
        } 
        else{
            booking_status = "Confirmed";
            cout << "Booking " << booking_id << " is now confirmed." << endl;
        }
    }

    void cancel_booking(){
        if (booking_status == "Cancelled"){
            cout << "Booking " << booking_id << " is already cancelled." << endl;
        } 
        else{
            booking_status = "Cancelled";
            cout << "Booking " << booking_id << " has been cancelled." << endl;
        }
    }

    void change_seat(){
        if (booking_status != "Confirmed") {
            cout << "Booking " << booking_id << " is not confirmed yet. Cannot change seat." << endl;
        } 
        else{
            string new_seat;
            cout << "Enter new seat number: ";
            cin.ignore();
            getline(cin, new_seat);
            cout << "Seat changed from " << seat_number << " to " << new_seat << " for booking " << booking_id << "." << endl;
            seat_number = new_seat;
        }
    }

    void display_booking(){
        cout << "\n--- Booking Details ---\n";
        cout << "Booking ID: " << booking_id << endl;
        cout << "Flight Details: " << flight_details << endl;
        cout << "Passenger Details: " << passenger_details << endl;
        cout << "Seat Number: " << seat_number << endl;
        cout << "Booking Status: " << booking_status << endl;
        cout << "Payment Information: " << payment_information << endl;
    }
};

int main() 
{
    Booking booking1;

    booking1.set_booking_details();
    booking1.display_booking();

    booking1.confirm_booking();
    booking1.change_seat();
    booking1.cancel_booking();

    booking1.display_booking();

    return 0;
}
