#include<iostream>
#include <map>


using namespace  std;

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
