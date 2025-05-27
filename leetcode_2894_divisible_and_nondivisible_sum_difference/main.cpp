class Solution {
public:
    int differenceOfSums(int n, int m) {
        int result = ((n+1)*n)/2; // Sum of all numbers
        for (int i = 1; i <= n; i++){
            if (i % m == 0) result -= 2*i; // Substract divisible numbers twice
        }
        return result;
    }
};