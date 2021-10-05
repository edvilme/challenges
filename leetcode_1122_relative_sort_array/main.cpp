#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        vector<int> arr1Unique;
        // Get order of elements in arr1
        for(int &i2 : arr2){
            for(int &i1 : arr1){
                if(i1 == i2) result.push_back(i1);
            }
        }
        // Get elements that exist in arr1 but dont on result
        for(int &i1 : arr1){
            bool found = false;
            for(int &iResult : result){
                if(i1 == iResult){
                    found = true;
                    break;
                }
            }
            if(!found) arr1Unique.push_back(i1);
        }
        // Sort arr1Unique
        sort(arr1Unique.begin(), arr1Unique.end());
        // Iterate to add items
        for(int &i1U : arr1Unique){
            result.push_back(i1U);
        }
        return result;
    }
};

void printVector(vector<int> v){
    for(int &item : v){
        cout << item << ", ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> case1{2,3,1,3,2,4,6,7,9,2,19};
    vector<int> case2{2,1,4,3,9,6};
    printVector(s.relativeSortArray(case1, case2));
    return 0;
}