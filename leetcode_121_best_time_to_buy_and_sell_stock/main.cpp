#include <limits.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* BRUTE FORCE
       int result = 0;
       for (int i = 0; i < prices.size(); i++){
           for (int j = i; j < prices.size(); j++){
               int profit = prices[j] - prices[i];
               if (profit > result) result = profit;
           }
       } 
       return result; */

        // Find smallest 
        int minimum = INT_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++){
            // Get profit for this day
            int profit = prices[i] - minimum;
            // Update minimum
            if (prices[i] < minimum) 
                minimum = prices[i];
            // If not min, substract min to get profit
            else if (profit > result)
                result = profit;
        }
        return result;
    }
};
