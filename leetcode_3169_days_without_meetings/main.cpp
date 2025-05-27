// Attempted. Failed time limit

class Solution {
public:
    void removeFromSetFromRangeInclusive(int& start, int& end, set<int>& base){
        for (int i = start; i <= end; i++) base.erase(i);
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        set<int> daysSet = {};
        for (int i = 1; i <= days; i++) daysSet.insert(i);
        
        for (vector<int>& meetingRange : meetings)  
            removeFromSetFromRangeInclusive(meetingRange[0], meetingRange[1], daysSet);

        return daysSet.size();
    }
};