class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negative = 0,
            possitive = 0;

        for (int i : nums){
            if (i < 0) negative++;
            if (i > 0) possitive++;
        }

        return max(negative, possitive);
    }
};