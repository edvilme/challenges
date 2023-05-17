#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int localMaxSum = 0;
        for (int i = 0; i < nums.size(); i++){
            // Add to sum so far
            localMaxSum += nums[i];
            // Check if accum sum is so far the biggest
            maxSum = max(localMaxSum, maxSum);
            // Reset if negative numbers
            localMaxSum = max(localMaxSum, 0);
        }
        return maxSum;
    }
};