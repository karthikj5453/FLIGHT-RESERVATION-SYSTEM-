#include<bits/stdc++.h>
using namespace std;

class Flight
{
    int flightNo;
    string from, to, depTime, arrTime;
    int capacityE, capacityB, capacityF;
    int bookedE, bookedB, bookedF;

public:
    Flight(int fn = 0, string f = "NA", string t = "NA", string dep = "00:00", string arr = "00:00", int ce = 100, int cb = 50, int cf = 10)
        : flightNo(fn), from(f), to(t), depTime(dep), arrTime(arr), capacityE(ce), capacityB(cb), capacityF(cf), bookedE(0), bookedB(0), bookedF(0) {}

    int getFlightNo() { return flightNo; }
    string getFrom() { return from; }
    string getTo() { return to; }

    bool bookSeat(string cls, int num)
    {
        if(cls == "E" && bookedE + num <= capacityE) { bookedE += num; return true; }
        if(cls == "B" && bookedB + num <= capacityB) { bookedB += num; return true; }
        if(cls == "F" && bookedF + num <= capacityF) { bookedF += num; return true; }
        return false;
    }

    bool cancelSeat(string cls, int num)
    {
        if(cls == "E" && bookedE - num >= 0) { bookedE -= num; return true; }
        if(cls == "B" && bookedB - num >= 0) { bookedB -= num; return true; }
        if(cls == "F" && bookedF - num >= 0) { bookedF -= num; return true; }
        return false;
    }

    void display()
    {
        cout << flightNo << " | " << from << " -> " << to << " | " << depTime << " - " << arrTime << "\n";
        cout << "E: " << bookedE << "/" << capacityE << " B: " << bookedB << "/" << capacityB << " F: " << bookedF << "/" << capacityF << endl;
    }

    void updateFile()
    {
        vector<string> lines;
        ifstream fin("flights.csv");
        string line;
        while (getline(fin, line))
        {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            int fn = stoi(token);
            if(fn == flightNo)
                line = to_string(flightNo) + "," + from + "," + to + "," + depTime + "," + arrTime + "," +
                       to_string(capacityE) + "," + to_string(capacityB) + "," + to_string(capacityF) + "," +
                       to_string(bookedE) + "," + to_string(bookedB) + "," + to_string(bookedF);
            lines.push_back(line);
        }
        fin.close();
        ofstream fout("flights.csv");
        for(auto &l : lines) fout << l << "\n";
        fout.close();
    }

    static vector<Flight*> loadFlights()
    {
        vector<Flight*> flights;
        ifstream fin("flights.csv");
        string line;
        while(getline(fin, line))
        {
            stringstream ss(line);
            string token;
            int fn, ce, cb, cf, be, bb, bf;
            string from, to, dep, arr;

            getline(ss, token, ','); fn = stoi(token);
            getline(ss, from, ','); getline(ss, to, ','); getline(ss, dep, ','); getline(ss, arr, ',');
            getline(ss, token, ','); ce = stoi(token);
            getline(ss, token, ','); cb = stoi(token);
            getline(ss, token, ','); cf = stoi(token);
            getline(ss, token, ','); be = stoi(token);
            getline(ss, token, ','); bb = stoi(token);
            getline(ss, token, ','); bf = stoi(token);

            Flight* f = new Flight(fn, from, to, dep, arr, ce, cb, cf);
            f->bookedE = be; f->bookedB = bb; f->bookedF = bf;
            flights.push_back(f);
        }
        fin.close();
        return flights;
    }
};
