#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class SeatManager {
private:
    vector<int> seats;
public:
    SeatManager(int n) {
        seats = vector<int>(n, 0);
        for(int i = seats.size() - 1; i >= 0; i--){
            seats[i] = seats.size() - i;
        }
    }
    
    int reserve() {
        int seat = seats[seats.size() - 1];
        seats.pop_back();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        for(int i = seats.size() - 1; i >= 0; i--){
            if(seats[i] > seatNumber){
                seats.insert(seats.end() - (seats.size() - 1 - i), seatNumber);
                return;
            }
        }

        seats.insert(seats.begin(), seatNumber);
        return;
    }
};

int main (){
    SeatManager sm(5);

    sm.reserve();
    sm.reserve();
    sm.unreserve(2);
    sm.reserve();
    sm.reserve();
    sm.reserve();

    return 0;
}