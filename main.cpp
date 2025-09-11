#include<iostream>
#include <map>
#include <string>


using namespace  std;

class passenger{

    private:
    int passenger_id;
    string name;
    string contact_information;
    string passport_details;


    public:
    void setdata(int id,string n,string contact,string passport){

        passenger_id=id;
        name = n;
        contact_information =contact;
        passport_details = passport;
    }
    void update_contact_info(string new_contact){
        contact_information = new_contact;
    }

    void display(){
        cout<<"passenger id: "<<passenger_id
            <<"name :"<<name
            <<"contact:"<<contact_information
            <<"passport:"<<passport_details<<endl;

    }
};


class Aircrafts{

    private:
    string manufacturer;
    string model;
    map<string,int> CabinCapacity;
    string seatmap;
    
    
    
    public:
    Aircrafts(string manufacturer="",string model=" "){
        manufacturer="manu";
        model="mo";

    }
    
     void addCabin(string cabinClass, int capacity) {
        CabinCapacity[cabinClass] = capacity;
    }
 
    int getTotalCapacity()  {
    int total = 0;
    for (auto &c : CabinCapacity) 
        total += c.second;
    return total;
}

void display_SeatCategories(){

    for(auto &a:CabinCapacity){
        cout<<a.first<<":"<<a.second<<endl;
        }
    }
};


int main(){
    passenger p1;
    p1.setdata(1,"karthik","777777777","CR7");
    
    cout<<"Passenger details "<< endl;
    p1.display();

    p1.update_contact_info("999999999");

    cout<<"\n after updating contact information" <<endl;
    p1.display();

    return 0;
}

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
        getline(cin,flight_details);

        cout<<"Enter Passenger Details: ";
        getline(cin,passenger_details);

        cout<<"Enter Seat Number: ";
        getline(cin,seat_number);

        cout<<"Enter Payment Information: ";
        getline(cin,payment_information);

        booking_status="Pending"; 
    }

    void confirm_booking(){
        if(booking_status=="Cancelled") {
            cout<<"Booking "<<booking_id<<"was cancelled. Cannot confirm."<<endl;
        } 
        else{
            booking_status="Confirmed";
            cout<<"Booking "<<booking_id<<" is now confirmed."<<endl;
        }
    }

    void cancel_booking(){
        if (booking_status=="Cancelled"){
            cout<<"Booking "<<booking_id<<" is already cancelled."<< endl;
        } 
        else{
            booking_status="Cancelled";
            cout<<"Booking "<<booking_id<<" has been cancelled."<<endl;
        }
    }

    void change_seat(){
        if (booking_status!="Confirmed"){
            cout<<"Booking "<<booking_id<<" is not confirmed yet. Cannot change seat."<< endl;
        } 
        else{
            string new_seat;
            cout<<"Enter new seat number: ";
            cin.ignore();
            getline(cin, new_seat);
            cout<<"Seat changed from "<<seat_number<<" to "<<new_seat<<" for booking "<<booking_id<<"."<< endl;
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




