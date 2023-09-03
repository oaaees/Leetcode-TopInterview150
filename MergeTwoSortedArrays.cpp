#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nums1{2,0};
    vector<int> nums2{1};
    int m = 1;
    int n = 1;

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3 = nums1;

        int i = 0, j = 0;

        if(n == 0) return;
        if(m == 0) {
            nums1 = nums2;
        }

        for(int k = 0; k < m+n; k++){
            if(nums1[i] <= nums2[j] && i < m){
                nums3[k] = nums1[i];
                i++;
            } else {
                nums3[k] = nums2[j];
                j++;
            }
        }

        nums1 = nums3;
    }

    void printVector(string name, vector<int> v){
        cout << name << " = [";

        for(int i = 0; i < v.size(); i++){
            if(i == v.size() - 1){
                cout << v[i];
                break;
            }
            cout << v[i] << ", ";
        }

        cout << "]\n";
    }

    void print(){
        printVector("nums1", nums1);
        printVector("nums2", nums2);
    }
};

int main (){
    Solution sol;
    sol.print();
    sol.merge(sol.nums1, sol.m, sol.nums2, sol.n);
    sol.print();
    return 0;
}