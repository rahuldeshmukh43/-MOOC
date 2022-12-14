#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct personInfo{
    int personID;
    int arrivalTime;
};

class busStop {
    private:
        static int id;
        queue<personInfo> busQueue; 
    public:
        void personArrives(int time);
        void boardBus(int busArrivalTime, int availableSeats);
};

int busStop::id = 1000;

void busStop::personArrives(int time) {
    personInfo person;
    person.personID = ++id;
    person.arrivalTime = time;
    busQueue.push(person);
    cout << "Person: " << busQueue.back().personID << ", " << busQueue.back().arrivalTime << endl;
}


void busStop::boardBus(int busArrivalTime, int availableSeats) {
    int i, count = 0, waitingTime, personArrivalTime = 0;
    for(i=1;i<=availableSeats;i++) {
        if (!busQueue.empty()) {
            personArrivalTime = busQueue.front().arrivalTime;
            if (busArrivalTime < personArrivalTime)
                waitingTime = 0;
            else
                waitingTime = busArrivalTime - personArrivalTime;
            cout << "\tWaiting time of " << busQueue.front().personID << ": " << waitingTime << endl; 
            count++;
            busQueue.pop();
        }
    }
    cout << "\t" << count << " people boarded the bus" << endl;
    if (!busQueue.empty())
        cout << "Next person in the queue: " << busQueue.front().personID << endl;
    else
        cout << "No body waiting in the bus queue" << endl;
}

int main() {
    busStop stop;
    int busArrivalTime;
    
    stop.personArrives(1415);
    stop.personArrives(1419);
    stop.personArrives(1421);
    stop.personArrives(1422);
    stop.personArrives(1427);

    busArrivalTime = 1430;
    cout << "Bus arrived at " << busArrivalTime << endl;    
    stop.boardBus(busArrivalTime,2);
    
    busArrivalTime = 1440;
    cout << "Bus arrived at " << busArrivalTime << endl;    
    stop.boardBus(busArrivalTime,7);

    busArrivalTime = 1450;
    cout << "Bus arrived at " << busArrivalTime << endl;    
    stop.boardBus(busArrivalTime,4);

    return 0;
}

/*
Output 
Person: 1001, 1415
Person: 1002, 1419
Person: 1003, 1421
Person: 1004, 1422
Person: 1005, 1427
Bus arrived at 1430
	Waiting time of 1001: 15
	Waiting time of 1002: 11
	2 people boarded the bus
Next person in the queue: 1003
Bus arrived at 1440
	Waiting time of 1003: 19
	Waiting time of 1004: 18
	Waiting time of 1005: 13
	3 people boarded the bus
No body waiting in the bus queue
Bus arrived at 1450
	0 people boarded the bus
No body waiting in the bus queue
*/

