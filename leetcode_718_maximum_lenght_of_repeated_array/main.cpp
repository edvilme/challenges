#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // Create 2d array to store values
        vector<vector<int>> mem(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for(int i = nums1.size() - 1; i >= 0; i--){
            for(int j = nums2.size() - 1; j >= 0; j--){
                if(nums1[i] == nums2[j]) mem[i][j] = mem[i+1][j+1] + 1;
            }
        }
        int max = 0;
        for(vector<int> &row : mem){
            for(int &value : row){
                if(value > max) max = value;
            }
        }
        return max;
    }
};

int main(){
    Solution s;
    vector<int> nums1 {1,2,3,2,1};
    vector<int> nums2 {3,2,1,4};
    cout << s.findLength(nums1, nums2) << endl;
    return 0;
}