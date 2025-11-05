#include<bits/stdc++.h>
using namespace std;

class USER{
    protected:
        string USER_ID;
        string USER_NAME;
        string USER_PASS;
        
    public:
        virtual bool LOGIN()=0;
        virtual void REGISTER_USER()=0;

        string GET_ID(){
            return USER_ID;
        }

        string GET_NAME(){
            return USER_NAME;
        }
};

class ADMIN_CLASS:public USER{
    public:
        bool LOGIN() override{
            cout<<"ENTER THE ADMIN ID : ";
            cin>>USER_ID;

            cout<<"ENTER THE ADMIN_NAME : ";
            cin>>USER_NAME;

            cout<<"ENTER THE ADMIN PASSWORD : ";
            cin>>USER_PASS;

        ifstream in("ADMIN_DETAILS.txt");
        if(!in){
            cout<<"\nNO ADMIN FOUND!!!!!!\nPLEASE REGISTER FIRST!!!!!!!\n";
            return false;
        }

        string ADMIN_ID;
        string NAME;
        string ADMIN_PASS;

        string line;
        bool found=false;

        while(getline(in,line)){

            if(line.find("ADMIN ID : ")!=string::npos){
                ADMIN_ID=line.substr(line.find(":") + 2); 
                getline(in,line); 

                NAME=line.substr(line.find(":") + 2);
                getline(in,line); 
                
                ADMIN_PASS=line.substr(line.find(":") + 2);

                if(ADMIN_ID==USER_ID && ADMIN_PASS==USER_PASS){
                    USER_NAME=NAME;
                    cout<<"\nADMIN LOGIN SUCCESFULLY!!!!!!!\n";
                    found=true;
                    break;
                }
            }
        }

        if(!found){
            cout<<"\nINVALID ADMIN DETAILS!!!!! SORRY!!!!!\n";
            return false;
        }

        return true;
    }

    void REGISTER_USER() override{
        cout<<"=======================REGISTER NEW ADMIN=============================\n";
        
        cout<<"CREATE ADMIN ID : ";
        cin>>USER_ID;

        cout<<"ENTER THE NAME : ";
        cin.ignore();
        getline(cin,USER_NAME);

        cout<<"CREATE PASSWORD : ";
        cin>>USER_PASS;

        ofstream out("ADMIN_DETAILS.txt",ios::app);
        out<<"ADMIN ID : "<<USER_ID<<"\n"<<"ADMIN NAME : "<<USER_NAME<<"\n"<<"PASSWORD : "<<USER_PASS<<"\n"<<"-------------------------------------------------\n";
        cout<<"\nADMIN REGISTRATION SUCCESFULLY!!!!!!!!!\n";
    }
};

class CUSTOMER_USER:public USER{
    public:
        bool LOGIN() override{
            cout<<"ENTER CUSTOMER ID : ";
            cin>>USER_ID;

            cout<<"ENTER THE CUSTOMER NAME : ";
            cin>>USER_NAME;

            cout<<"ENTER THE PASSWORD : ";
            cin>>USER_PASS;

            ifstream in("CUSTOMER_DETAILS.txt");
            if(!in){
                cout<<"\nNO CUSTOMER FOUND!!!!! PLEASE FIRST REGISTER!!!!!!!\n";
                return false;
            }

            string CUSTOMER_ID;
            string CUSTOMER_NAME;
            string CUSTOMER_PASS;

            string line;
            bool found=false;

            while(getline(in,line)){
                if(line.find("CUTOMER ID : ")!=string::npos){

                    CUSTOMER_ID=line.substr(line.find(":")+2);  
                    getline(in,line); 

                    CUSTOMER_NAME=line.substr(line.find(":")+2);
                    getline(in,line); 

                    CUSTOMER_PASS=line.substr(line.find(":")+2);

                    if(CUSTOMER_ID==USER_ID && CUSTOMER_PASS==USER_PASS){
                        USER_NAME = CUSTOMER_NAME;
                        cout << "\nCUSTOMER LOGIN SUCCESSFULL!!!\n";
                        found = true;
                        break;
                    }
                }
            }

            if(!found){
                cout<<"\nINVALID CUSTOMER DETAILS!!!! SORRY!!!!\n";
                return false;
            }
            return true;
        }

        void REGISTER_USER() override{
            cout<<"\n==============REGISTER NEW CUSTOMER===================\n";
            
            cout<<"CREATE CUSTOMER ID : ";
            cin>>USER_ID;

            cout<<"ENTER THE NAME OF THE CUSTOMER : ";
            cin.ignore();
            getline(cin,USER_NAME);

            cout<<"CREATE THE PASSWORD : ";
            cin>>USER_PASS;

            ofstream out("CUSTOMER_DETAILS.txt",ios::app);
            out<<"CUTOMER ID : "<<USER_ID<<"\n"<<"NAME : "<<USER_NAME<<"\n"<<"PASSWORD : "<<USER_PASS<<"\n"<<"----------------------------------------------\n";
            cout<<"\nCUTOMER REGISTED SUCCEFULLY!!!!!!!\n";
        }
};

class Passenger{
    protected:
        int PERSON_ID;
        string PASSENGER_NAME;
        int Age;
        string GENDER;

    public:
        Passenger(){
            PERSON_ID=0;
            PASSENGER_NAME="";
            Age=0;
            GENDER="";
        }

        Passenger(int ID,string name,int age,string gender){
            PERSON_ID=ID;
            PASSENGER_NAME=name;
            Age=age;
            GENDER=gender;
        }

        ~Passenger(){

        }

        virtual void SAVE_PASSENGER_DETAILS(){
            ifstream in("PASSENGER_Details.txt");

            string line;
            bool exist=false;

            while(getline(in,line)){
                if(line.find("PASSENGER ID : "+to_string(PERSON_ID))!=string::npos){
                    exist=true;
                    break;
                }
            }
            in.close();

            if(exist){
                cout << "\nPASSENGER ALREADY EXIST!!!! SORRY WE CAN'T ADD!!!!" << "\n";
                return;
            }
            else{
                ofstream out("PASSENGER_Details.txt",ios::app);
                out<<"PASSENGER ID : "<<PERSON_ID<<"\n"<<"PASSENGER NAME : "<<PASSENGER_NAME << "\n"<<"AGE : "<<Age<<"\n"<<"GENDER : "<<GENDER<<"\n"<<"----------------------------"<<"\n";
                out.close();
            }
            cout<<"\nPASSENGER DETAILS SAVED!!!"<<"THANK YOU!!!"<<"\n\n";
        }

        virtual void SHOW_PASSENGERS_DETAILS(){
            cout<<"PASSENGER ID : "<<PERSON_ID<<"\n";
            cout<<"PASSENGER NAME : "<<PASSENGER_NAME<<"\n";
            cout<<"AGE : "<<Age<<"\n";
            cout<<"GENDER : "<<GENDER<<"\n";
        }

    friend void SHOW_ALL_PASSENGERS();
};

class FLIGHT{
    protected:
        string FLIGHT_NO;
        string FLIGHT_NAME;
        string TAKE_OFF_FROM;
        string LAND_TO;
        string DATE;
        string TIME;
        double PRICE;

    public:
        FLIGHT(){
            FLIGHT_NO="";
            FLIGHT_NAME="";
            TAKE_OFF_FROM="";
            LAND_TO="";
            DATE="";
            TIME="";
            PRICE=0.0;
        }

        FLIGHT(string FLIGHT_NUMBER,string AIRLINE,string FLIGHT_TAKE_OFF,string FLIGHT_LAND,string FLIGHT_DATE,string FLIGHT_TIME,double price){
            FLIGHT_NO=FLIGHT_NUMBER;
            FLIGHT_NAME=AIRLINE;
            TAKE_OFF_FROM=FLIGHT_TAKE_OFF;
            LAND_TO=FLIGHT_LAND;
            DATE=FLIGHT_DATE;
            TIME=FLIGHT_TIME;
            PRICE=price;
        }

        ~FLIGHT(){
            
        }

        virtual void SAVE_FLIGHT_DETAILS(){
            ifstream in("FLIGHT_details.txt");

            string line;
            bool exist=false;

            string flightLine="FLIGHT NUMBER : "+FLIGHT_NO;
            string fromLine="FROM : "+TAKE_OFF_FROM;
            string destLine="DESTINATION : "+LAND_TO;

            while(getline(in, line)){
                if(line==flightLine){
                      string airline;
                    string tempFrom;
                    string tempDest;
                    getline(in,tempFrom); 
                    getline(in,tempDest); 
                      getline(in,DATE);
                    getline(in,TIME);
                    getline(in,line); 

                   if(airline==airlineLine && tempFrom==fromLine && tempDest==destLine && DATE==DATE && TIME==TIME){
                        exist=true;
                        break;
                    }
                }
            }
            in.close();

            if(exist){
                cout<<"THE FLIGHT ALREADY EXISTS FOR THIS ROUTE!!!! SORRY WE CAN'T ADD!!!\n\n";
                return;
            }   
            else{
            ofstream out("FLIGHT_details.txt",ios::app);
            out<<"FLIGHT NUMBER : "<<FLIGHT_NO<<"\n"<<"AIRLINE : "<<FLIGHT_NAME<<"\n"<<"FROM : "<<TAKE_OFF_FROM<<"\n"<<"DESTINATION : "<<LAND_TO<<"\n"<<"DATE : "<<DATE<<"\n"<<"TIME : "<<TIME<<"\n"<<"PRICE : "<<PRICE<<"\n"<<"-------------------------------------"<<"\n";
            out.close();
        }
        cout<<"\nFLIGHT ADD SUCCESFULLY!!!! NOW LET'S FLY!!!!!!"<<"\n\n";
    }

        virtual void SHOW_FLIGHT_DETAILS(){
            cout<<"FLIGHT NUMBER : "<<FLIGHT_NO<<"\n";
            cout<<"FROM : "<<TAKE_OFF_FROM<<"\n";
            cout<<"DESTINATION : "<<LAND_TO<<"\n";
            cout<<"DATE : "<<DATE<<"\n";
            cout<<"TIME : "<<TIME<<"\n";
            cout<<"PRICE : "<<PRICE<<"\n";
        }

    friend void SHOW_ALL_FLIGHTS();
};

class BOOKING:public Passenger,public FLIGHT{
    protected:
        int BOOKING_ID;
        static int COUNTER;

    public:
        BOOKING(){
            BOOKING_ID = 0;
        }

        BOOKING(int ID,string name,int PASSENGER_AGE,string Passenger_gender,string FL_NUMBER,string AIRLINE,string Take,string DESTI,string date,string time,double price):Passenger(ID,name,PASSENGER_AGE,Passenger_gender),FLIGHT(FL_NUMBER,AIRLINE,Take,DESTI,date,time,price){
            BOOKING_ID=++COUNTER;
            savecounter(COUNTER);
        }

        ~BOOKING(){

        }

        void SAVE_BOOKINGS(){
            ofstream out("BOOKING_DETAILS.txt",ios::app);
            out<<"BOOKING ID : "<<BOOKING_ID<<"\n"<<"PASSENGERS ID : "<<PERSON_ID<<"\n"<<"PASSENGER NAME : "<<PASSENGER_NAME<<"\n"<<"PASSENGER AGE : "<<Age <<"\n"<<"PASSENGER GENDER : "<<GENDER<<"\n"<<"FLIGHT NUMBER : "<<FLIGHT_NO<<"\n"<<"FROM : "<<TAKE_OFF_FROM<<"\n"<<"DESTINATION : "<<LAND_TO<<"\n"<<"DATE : "<<DATE<<"\n"<<"TIME : "<<TIME<<"\n"<<"PRICE : "<<PRICE<<"\n"<<"---------------------------------------\n";
            out.close();
        }

        void SHOW_PASSENGERS_DETAILS() override{
            cout<<"BOOKING ID : "<<BOOKING_ID<<"\n";
            Passenger::SHOW_PASSENGERS_DETAILS();
        }

        void SHOW_FLIGHT_DETAILS() override{
            cout<<"\n--- BOOKING'S FLIGHT DETAILS ---\n";
            cout<<"BOOKING ID : "<<BOOKING_ID<<"\n";
            FLIGHT::SHOW_FLIGHT_DETAILS(); 
        }

        void SHOW_ALL_BOOKINGS(){
            ifstream in("BOOKING_DETAILS.txt");

            if(!in){
                cout<<"\nNO ANY BOOKING!!!!!!! SORRY!!!!!\n\n";
                return;
            }

            cout<<"\n========================ALL BOOKINGS=================================\n";
            string line;
            while(getline(in,line)){
                cout<<line<<"\n";
            }
            cout<<"\n";
            in.close();
        }

        bool operator==(const BOOKING &b){
            return BOOKING_ID == b.BOOKING_ID;
        }

    static int loadcounter(){
        ifstream in("BOOKING_COUNTER.txt");
        int c=0;
        if(in){
            in>>c;
        }
        in.close();
        return c;
    }

    void savecounter(int c){
        ofstream out("BOOKING_COUNTER.txt");
        out<<c;
        out.close();
    }

    friend void SHOW_BOOKING_FRIEND(const BOOKING &b);
    friend void SHOW_ALL_CANCELLATION_BOOKINGS();
};

int BOOKING::COUNTER=BOOKING::loadcounter();

class CANCEL_BOOKINGS:public Passenger,public FLIGHT{
    public:
        int BID;

        CANCEL_BOOKINGS(int BOOKING_ID,int ID,string name,int age,string gender,string flight_no,string airline,string from,string to,string date,string time,double price):Passenger(ID,name,age,gender),FLIGHT(flight_no,airline,from,to,date,time,price){
            BID=BOOKING_ID;
        }

        CANCEL_BOOKINGS(int BOOKING_ID, int ID, string name, string flight_no){
            BID=BOOKING_ID;
            PERSON_ID=ID;
            PASSENGER_NAME=name;
            FLIGHT_NO=flight_no;
        }

        void CANCEL_BOOKING(){
            ifstream inFile("BOOKING_DETAILS.txt");
            ofstream tempFile("temp.txt");
            ofstream cancel("CANCEL_BOOING_DETAILS.txt",ios::app);

            string line;
            bool skip=false;
            bool found=false;

            while(getline(inFile, line)){
                if(line.find("BOOKING ID : "+to_string(BID))!=string::npos){
                    skip=true;
                    found=true;
                }

                if(skip){
                    cancel<<line<<"\n";
                }
                else{
                    tempFile<<line<<"\n";
                }

                if(skip && line.find("---------------------------------------")!=string::npos){
                    skip=false;
                }
            }
            inFile.close();
            tempFile.close();
            cancel.close();

        if (!found){
            cout<<"BOOKING ID NOT FOUND!!!!"<<"\n";
            remove("temp.txt");
            return;
        }

        remove("BOOKING_DETAILS.txt");
        rename("temp.txt", "BOOKING_DETAILS.txt");

        cout<<"\nBOOKING CANCELLED SUCCESFULLY!!!!! GOOD!!!!\n\n";
    }
};

void SHOW_BOOKING_FRIEND(const BOOKING &b)
{
    cout<<"BOOKING ID : "<<b.BOOKING_ID<<"\n";
    cout<<"PASSENGER ID : "<<b.PERSON_ID<<"\n";
    cout<<"PASSENGER NAME : "<<b.PASSENGER_NAME<<"\n";
}

void SHOW_ALL_PASSENGERS(){
    ifstream in("PASSENGER_Details.txt");

    if(!in){
        cout<<"THERE IS NO ANY PASSENGER!!!!! SORRY!!!!"<<"\n";
        return;
    }

    cout<<"\n===========================ALL PASSENGERS==========================\n";

    string line;
    while(getline(in, line)){
        cout<<line<<"\n";
    }
    cout<<"\n";
    in.close();
}

void SHOW_ALL_FLIGHTS(){
    ifstream in("FLIGHT_details.txt");

    if(!in){
        cout<<"NO FLIGHT IS THERE!!!! SORRY!!!!"<<"\n";
        return;
    }
    cout<<"\n==============================ALL FLIGHTS==============================\n";
    
    string line;
    while(getline(in, line)){
        cout<<line<<"\n";
    }
    cout<<"\n";
    in.close();
}

void SHOW_ALL_CANCELLATION_BOOKINGS(){
    ifstream in("CANCEL_BOOING_DETAILS.txt");
    
    if(!in){
        cout<<"NO CANCELLATION IS THERE!!!!!  ENJOY!!!!"<<"\n";
        return;
    }

    cout<<"\n=================================ALL CANCELATION BOOKINGS============================\n";
    
    string line;
    while(getline(in, line)){
        cout<<line<<"\n";
    }
    cout<<"\n";
    in.close();
}

void ADMIN_MENU(){
    int CHOOSE;
    do{
        cout<<"===========ADMIN MENU============\n";
        cout<<"1 ADD FLIGHT\n";
        cout<<"2 VIEW FLIGHS\n";
        cout<<"3 VIEW PASSENGERS\n";
        cout<<"4 VIEW BOOKINGS\n";
        cout<<"5 VIEW CANCEL BOOKINGS\n";
        cout<<"6 LOGOUT\n";

        try{
            cout<<"ENTER YOUR CHOICE : ------------------------------>";
            if(!(cin>>CHOOSE)){
                throw runtime_error("INVALID INPUT!!!!!\n");
            }
        }
        catch(const exception &e){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            CHOOSE=0;
        }

        switch(CHOOSE){
            case 1:
            {
                string FLIGHT_NO;
                string AIRLINE;
                string FROM;
                string TO;
                string DATE;
                string TIME;
                double price;

                cout<<"FLIGHT NUMBER : ";
                cin>>FLIGHT_NO;

                cout<<"AIRLINE NAME : ";
                cin>>AIRLINE;

                cout<<"FORM : ";
                cin>>FROM;

                cout<<"TO : ";
                cin>>TO;

                cout<<"DATE : ";
                cin>>DATE;

                cout<<"TIME : ";
                cin>>TIME;

                cout<<"PRICE : ";
                cin>>price;
                
                FLIGHT flight(FLIGHT_NO,AIRLINE,FROM,TO,DATE,TIME,price);
                flight.SAVE_FLIGHT_DETAILS();
                break;
            }

            case 2:
            {
                SHOW_ALL_FLIGHTS();
                break;
            }

            case 3:
            {
                SHOW_ALL_PASSENGERS();
                break;
            }

            case 4:
            {
                BOOKING b;
                b.SHOW_ALL_BOOKINGS();
                break;
            }

            case 5:
            {
                SHOW_ALL_CANCELLATION_BOOKINGS();
                break;
            }

            case 6:
            {
                cout<<"\nLOG OUT!!!! THANK YOU!!!"<<"\n\n";
                break;
            }

            default:
                cout<<"\nINVALID INPUT!!!!\n\n";
                break;
        }
    }while(CHOOSE!=6);
}

void CUSTOMER_MENU(){
    int choose;

    do{
        cout<<"==============CUSTOMER MENU=================\n";
        cout<<"1 ADD PASSENGER\n";
        cout<<"2 VIEW FLIGHTS\n";
        cout<<"3 BOOK TICKET\n";
        cout<<"4 CANCEL TICKET\n";
        cout<<"5 LOGOUT\n";

        try{
            cout<<"ENTER YOUR CHOICE : ------------------------------>";
            if(!(cin>>choose)){
                throw runtime_error("INVALID INPUT!!!!!\n");
            }
        }
        catch(const exception &e){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            choose=0;
        }

        switch(choose){
            case 1:
            {
                int id;
                string name;
                int age;
                string gender;

                cout<<"PASSENGER ID : ";
                cin>>id;

                cout<<"ENTER THE NAME : ";
                cin.ignore();
                getline(cin,name);

                cout<<"AGE : ";
                cin>>age;

                cout<<"GENDER : ";
                cin>>gender;
                Passenger P(id,name,age,gender);
                P.SAVE_PASSENGER_DETAILS();
                break;
            }

            case 2:
            {
                SHOW_ALL_FLIGHTS();
                break;
            }

            case 3:
            {
                int ID;
                string NAME;
                int AGE;
                string GENDER;
                string FLIGHT_NO;
                string AIRLINE;
                string FROM;
                string TO;
                string DATE;
                string TIME;
                double price;

                cout<<"PASSENGER ID : ";
                cin>>ID;

                cout<<"NAME : ";
                cin>>NAME;

                cout<<"AGE : ";
                cin>>AGE;

                cout<<"GENDER : ";
                cin>>GENDER;
                
                cout<<"\n======================AVAILABLE FLIGHTS=====================\n";
                SHOW_ALL_FLIGHTS();
                
                cout<<"FLIGHT NUMBER : ";
                cin>>FLIGHT_NO;

                cout<<"AIRLINE : ";
                cin.ignore();
                getline(cin,AIRLINE);

                cout<<"FROM : ";
                cin>>FROM;

                cout<<"TO : ";
                cin>>TO;

                cout<<"DATE : ";
                cin>>DATE;

                cout<<"TIME : ";
                cin>>TIME;

                cout<<"PRICE : ";
                cin>>price;
                try{
                    BOOKING *b=new BOOKING(ID,NAME,AGE,GENDER,FLIGHT_NO,AIRLINE,FROM,TO,DATE,TIME,price);
                    b->SAVE_BOOKINGS();
                    delete b;
                }
                catch(const bad_alloc &e){
                    cout<<"MEMORY ALLOCATION FAILED"<<"\n";
                }
               
                break;
            }

            case 4:
            {
                int bid;
                int id;
                string name;
                string flight_no;

                cout<<"ENTER BOOKING ID : ";
                cin>>bid;

                cout<<"ENTER THE PASSENGER ID : ";
                cin>>id;

                cout<<"ENTER THE NAME : ";
                cin.ignore();
                getline(cin,name);

                cout<<"ENTER THE FLIGHT NUMBER : ";
                cin>>flight_no;

                CANCEL_BOOKINGS cancel(bid,id,name,flight_no);
                cancel.CANCEL_BOOKING();
                break;
            }

            case 5:
            {
                cout<<"\nLOG OUT!!!! THANK YOU!!!"<<"\n\n";
                break;
            }

            default:
                cout<<"\nINVALID INPUT!!!!\n\n";
                break;
        }
    }while(choose!=5);
}

int main()
{
    int choose;
    do{
        cout<<"=======FLIGHT RESERVATION SYSTEM==============\n";
        cout<<"1 ADMIN LOGIN"<<"\n";
        cout<<"2 ADMIN REGISTRATION"<<"\n";
        cout<<"3 CUSTOMER LOGIN"<<"\n";
        cout<<"4 CUSTOMER REGISTRATION"<<"\n";
        cout<<"5 EXIT"<<"\n";

        try{
            cout<<"ENTER YOUR CHOICE : ------------------------------>";
            if(!(cin>>choose)){
                throw runtime_error("INVALID INPUT!!!!!\n");
            }
        }
        catch(const exception &e){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            choose=0;
        }

        switch(choose){
            case 1:
            {
                ADMIN_CLASS ADMIN;
                if(ADMIN.LOGIN()){
                    ADMIN_MENU();
                }
                else{
                    char ans;
                    cout<<"\nDO YOU WANT TO REGISTER NEW ADMIN(y/n) : ";
                    cin>>ans;

                    if(ans=='y' || ans=='Y'){
                        ADMIN.REGISTER_USER();
                    }
                }
                break;
            }

            case 2:
            {
                ADMIN_CLASS ADMIN;
                ADMIN.REGISTER_USER();
                break;
            }

            case 3:
            {
                CUSTOMER_USER CUSTOMER;
                if(CUSTOMER.LOGIN()){
                    CUSTOMER_MENU();
                }
                else{
                    char ans;
                    cout<<"DO YOU WANT TO REGISTER THE NEW CUSTOMER(y/n) : ";
                    cin>>ans;

                    if(ans=='y' || ans=='Y'){
                        CUSTOMER.REGISTER_USER();
                    }
                }
                break;
            }

            case 4:
            {
                CUSTOMER_USER customer;
                customer.REGISTER_USER();
                break;
            }

            case 5:
            {
                cout<<"\n EXITING SYSTEM!!!! BYEE BYE!!!!!!!!!!";
                return 0;
            }

            default:
                cout<<"\nINVALID INPUT!!!\n\n";
        }
    }while(choose!=5);
}

