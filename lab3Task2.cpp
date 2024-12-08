#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

bool random_event(double probability) {
    return (rand() % 100) < (probability * 100);
}

int main() {
    int endtime;             
    double expectarrive;    
    double expectdepart;   
    
    
    int nplanes = 0;      
    int nland = 0;           
    int ntakeoff = 0;       
    int nrefuse = 0;         
    int idletime = 0;       
    int landwait = 0;        
    int takeoffwait = 0;     
    
    queue<int> landingQueue; 
    queue<int> takeoffQueue; 
    
    cout << "Enter total simulation time (units): ";
    cin >> endtime;
    cout << "Enter expected number of planes arriving per unit time (0 to 1): ";
    cin >> expectarrive;
    cout << "Enter expected number of planes ready to take off per unit time (0 to 1): ";
    cin >> expectdepart;

    for (int curtime = 1; curtime <= endtime; curtime++) {
        cout << "\nTime Unit: " << curtime << endl;
        
        if (random_event(expectarrive)) {
            if (landingQueue.size() < 5) { 
                landingQueue.push(curtime);
                cout << "Plane added to landing queue." << endl;
            } else {
                nrefuse++;
                cout << "Landing queue is full. Plane refused." << endl;
            }
        }

        if (random_event(expectdepart)) {
            if (takeoffQueue.size() < 5) { 
                takeoffQueue.push(curtime); 
                cout << "Plane added to takeoff queue." << endl;
            } else {
                nrefuse++;
                cout << "Takeoff queue is full. Plane refused." << endl;
            }
        }

        if (!landingQueue.empty()) {
            int arrival_time = landingQueue.front();
            landingQueue.pop(); 
            nland++;        
            nplanes++;       
            landwait += (curtime - arrival_time);
            cout << "Plane landed. Wait time: " << (curtime - arrival_time) << endl;
        } else if (!takeoffQueue.empty()) {
            int arrival_time = takeoffQueue.front();
            takeoffQueue.pop();
            ntakeoff++;         
            nplanes++;      
            takeoffwait += (curtime - arrival_time); 
            cout << "Plane took off. Wait time: " << (curtime - arrival_time) << endl;
        } else {
            idletime++;
            cout << "Runway is idle." << endl;
        }
    }

    cout << "\nSimulation Results:" << endl;
    cout << "Total number of planes processed: " << nplanes << endl;
    cout << "Number of planes landed: " << nland << endl;
    cout << "Number of planes taken off: " << ntakeoff << endl;
    cout << "Number of planes refused: " << nrefuse << endl;
    cout << "Percentage of time runway was idle: " << (idletime * 100.0 / endtime) << "%" << endl;
    cout << "Average wait time for landing: " << (nland > 0 ? landwait / nland : 0) << " units" << endl;
    cout << "Average wait time for takeoff: " << (ntakeoff > 0 ? takeoffwait / ntakeoff : 0) << " units" << endl;
    cout << "Planes left in landing queue: " << landingQueue.size() << endl;
    cout << "Planes left in takeoff queue: " << takeoffQueue.size() << endl;

    return 0;
}
