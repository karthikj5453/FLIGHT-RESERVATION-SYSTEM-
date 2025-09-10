#include<iostream>
#include<string>
using namespace std;

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