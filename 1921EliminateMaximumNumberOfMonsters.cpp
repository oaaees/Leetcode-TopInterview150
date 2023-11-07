#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> steps(n, 0);

        for(int i = 0; i < n; i++){
            steps[i] = dist[i] / speed[i];
            if(dist[i] % speed[i] != 0) steps[i]++;
        }

        sort(steps.begin(), steps.end());

        int count = 0;
        for(int i = 0; i < n; i++){
            if(steps[i] - count <= 0 && i > 0) break;
            count++;
        }

        return count;
    }
};

int main (){
    Solution sol;
    vector<int> dist = {10,8,15,16,18,20,63,45,140};
    vector<int> speed = {1,2,3,4,5,6,7,8,9};

    cout << sol.eliminateMaximum(dist, speed);

    return 0;
}