#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size(); j++){
                int difference = nums[j] - nums[i];
                if( difference > 0 && difference > maxDiff) maxDiff = difference;
            }
        }
        return maxDiff;
    }
};

