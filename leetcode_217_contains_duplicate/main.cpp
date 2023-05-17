#include <bits/stdc++.h>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sort vector
        sort(nums.begin(), nums.end());
        // Iterate array
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};
