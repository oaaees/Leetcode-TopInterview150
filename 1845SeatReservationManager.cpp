#include <vector>
#include <iostream>
using namespace std;

class SeatManager {
private: 
    int min;
    vector<bool> seats;
public:
    SeatManager(int n) {
        min = 0;
        seats = vector<bool>(n, true);
    }
    
    int reserve() {
        seats[min] = false;
        int r = min;

        if(seats[min + 1]){
            min++;
            return min - 1;
        }

        for(int i = min; i < seats.size(); i++){
            if(seats[i]){
                min = i;
            }
        }

        return r;
    }
    
    void unreserve(int seatNumber) {
        seats[seatNumber - 1] = true;
    }

    void print(){
        for(bool b : seats){ cout << b; }
        cout << '\n';
    }
};

int main (){
    SeatManager sm(5);
    sm.reserve();
    sm.print();
    sm.reserve();
    sm.print();
    sm.reserve();
    sm.print();


    return 0;
}