class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                int sum = nums[i] + nums[j];
                if (sum == target){
                    return vector<int> {i, j};
                }
            }
        }
        return vector<int> {0,0};
    }
};
