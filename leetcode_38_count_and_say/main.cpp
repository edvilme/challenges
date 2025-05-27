# include <stdio.h>

using namespace std;

class Solution {
public:

    vector<string> groupByConsecutiveChars(string base) {
        vector<string> result = {};
        char currentChar;

        for (int i = 0; i < base.size(); i++) {
            if (base[i] != currentChar) {
                result.push_back("");
                currentChar = base[i];
            }
            result[result.size() - 1] += currentChar;
        }

        return result;
    }

    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n-1);
        vector<string> prevGrouped = groupByConsecutiveChars(prev);
        string result = "";

        for (int i = 0; i < prevGrouped.size(); i++){
            result += (to_string(prevGrouped[i].size()) + prevGrouped[i][0]);
        }

        return result;
    }
};