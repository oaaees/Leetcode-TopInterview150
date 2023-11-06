#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class SeatManager {
private:
    priority_queue <int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        for(int i = 1; i <= n; i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int seat = pq.top();
        pq.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
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