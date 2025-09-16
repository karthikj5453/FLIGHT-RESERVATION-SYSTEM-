#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Aircrafts {
private:
    string manufacturer;
    string model;
    map<string, vector<string>> seatMap;  //TODO: NEED TO IMRPOVE THIS (ADD FILE HANDLING,OR PROPER LAYOUT)

public:
    Aircrafts(string manufacturer = "", string model = "") {
        this->manufacturer = manufacturer;
        this->model = model;
        generateSeatMap();  
    }

    ~Aircrafts() { }

   
    void displaySeatMap() {
        for (auto &cabin : seatMap) {
            cout << cabin.first << " Class: ";
            for (auto &seat : cabin.second) cout << seat << " ";
            cout << endl;
        }
    }

    
    void displaySeatMap(string cabinClass) {
        if (seatMap.count(cabinClass)) {
            cout << cabinClass << " Class: ";
            for (auto &seat : seatMap[cabinClass]) cout << seat << " ";
            cout << endl;
        } else {
            cout << "No such cabin class.\n";
        }
    }


    friend void bookSeat(Aircrafts &a, string cabin, string seatNo);

private:
    void generateSeatMap() {
        if (model == "Boeing737") { //TODO:  trying more codes and models and file handling 
            
            for (int row = 1; row <= 4; row++) {
                for (char s = 'A'; s <= 'F'; s++) {
                    seatMap["Business"].push_back(to_string(row) + s);
                }
            }

            
            for (int row = 5; row <= 30; row++) {
                for (char s = 'A'; s <= 'F'; s++) {
                    seatMap["Economy"].push_back(to_string(row) + s);
                }
            }
        }
    }
};


void bookSeat(Aircrafts &a, string cabin, string seatNo) {
    for (auto &seat : a.seatMap[cabin]) {
        if (seat == seatNo) {
            if (seat == "X") {
                cout << "Seat already booked!\n";
                return;
            }
            seat = "X";
            cout << "Seat " << seatNo << " booked successfully!\n";
            return;
        }
    }
    cout << "Invalid seat number.\n";
}

int main() {
    Aircrafts* a1 = new Aircrafts("Boeing", "Boeing737");

    cout << "Initial seat map (partial display):\n";
    a1->displaySeatMap("Business");
    a1->displaySeatMap("Economy");


    string cabin, seatNo;
    char choice = 'y';
    while (choice == 'y') {
        cout << "\nEnter Cabin (Business/Economy): ";
        cin >> cabin;
        cout << "Enter Seat Number (e.g., 3A, 15C): ";
        cin >> seatNo;

        bookSeat(*a1, cabin, seatNo);

        cout << "\nUpdated " << cabin << " Class:\n";
        a1->displaySeatMap(cabin);

        cout << "\nBook another seat? (y/n): ";
        cin >> choice;
    }

    delete a1;
    return 0;
}
