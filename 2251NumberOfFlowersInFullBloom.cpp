#include <vector>
#include <algorithm>  
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> res(people.size(), 0);
        int count = 0;

        vector<int> start = {};
        vector<int> end = {};
        vector<vector<int>> p = {};

        for(int i = 0; i < flowers.size(); i++){
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }

        for(int i = 0; i < people.size(); i++){
            p.push_back({people[i], i});
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        sort(p.begin(), p.end(), [](vector<int> a, vector<int> b){return (a[0]<b[0]);});

        int last_start = 0;
        int last_end = 0;

        for(int i = 0; i < people.size(); i++){
            while(last_start < start.size() && start[last_start] <= p[i][0]){ count++; last_start++; }
            while(last_end < end.size() && end[last_end] < p[i][0]) {count--; last_end++; }
            res[p[i][1]] = count;
        }

        return res;
    }
};

int main (){
    Solution sol;
    vector<vector<int>> flowers = {{1,10},{3,3}};
    vector<int> people = {1,3,2};

    vector<int> bloomed = sol.fullBloomFlowers(flowers, people);

    for(int x : bloomed){
        cout << x << " ";
    }

    return 0;
}