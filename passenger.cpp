#include <bits/stdc++.h>
using namespace std;
class passenger
{
private:
    int passenger_ID;
    string name;
    string contact_info;
    string passport_details;
public:
    passenger(int ID = 0, string n = "", string contact = "", string passport = "")
    {
        passenger_ID = ID;
        name = n;
        contact_info = contact;
        passport_details = passport;
    }
    ~passenger(){}
    void setdata(int ID, string n, string contact, string passport)
    {
        passenger_ID = ID;
        name = n;
        contact_info = contact;
        passport_details = passport;
    }
    void update_contact_info(string new_contact)
    {
        contact_info = new_contact;
    }
    void show_info()
    {
        cout << "Passenger ID: " << passenger_ID
             << " -> Name: " << name
             << " -> Contact: " << contact_info
             << " -> Passport: " << passport_details << endl;
    }
};
int main()
{
    passenger p1;
    p1.setdata(1, "Karthik", "777777777", "CR7");
    cout << "Passenger Details " << endl;
    p1.show_info();
    p1.update_contact_info("999999999");
    cout << "\nUpdated Contact Info:" << endl;
    p1.show_info();
    return 0;
}
