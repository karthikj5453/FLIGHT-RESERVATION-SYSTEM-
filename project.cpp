#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class Aircrafts {
private:
    string airline;
    string manufacturer;
    string model;
    map<string,int> CabinCapacity;
    string seatmap;
    int totalseats = 0;

public:
    Aircrafts() {}

    Aircrafts(string a = " ", string m = " ", string mo = " ") {
        airline = a;
        manufacturer = m;
        model = mo;
    }

    void addCabin(string cabinClass, int capacity) {
        CabinCapacity[cabinClass] = capacity;
    }

    int getTotalCapacity() {
        totalseats = 0;  
        for (auto &c : CabinCapacity) 
            totalseats += c.second;
        return totalseats;
    }

    void display_SeatCategories() {
        for(auto &a : CabinCapacity){
            cout << a.first << " : " << a.second << endl;
        }
    }

    void printAircraftdetails() {
        cout << airline << endl;
        cout << manufacturer << endl;
        cout << model << endl;
  
        for (auto &entry : CabinCapacity) {
            cout << entry.first << " : " << entry.second << endl;
        }

        cout << "Total Seats: " << getTotalCapacity() << endl;
    }
};

int main() {
    
    Aircrafts* a1 = new Aircrafts("Indigo", "Airbus", "A320");
    a1->addCabin("Economy", 180);
    a1->addCabin("Business", 20);
    a1->printAircraftdetails();
    a1->display_SeatCategories();
    a1->getTotalCapacity();
    

    cout << endl;

    Aircrafts* a2 = new Aircrafts("Emirates", "Boeing", "777");
    a2->addCabin("Economy", 300);
    a2->addCabin("Business", 50);
    a2->addCabin("First", 10);
    a2->printAircraftdetails();
    

  
    
    delete a1;
    delete a2;

    return 0;
}
