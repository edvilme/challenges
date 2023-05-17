class Solution {
public:
    bool isAnagram(string s, string t) {
        // Sort words
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        // Return
        return s == t;
    }
};
