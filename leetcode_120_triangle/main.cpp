#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    cout << "[";
    for(int &item : v) cout << item << " ";
    cout << "]";
}

int minimumTotal(vector<vector<int>> &triangle){
    vector<int> bottomRow( triangle[triangle.size()-1].size() + 1, 0 );
    for(int i = triangle.size()-1; i >= 0; i--){
        vector<int> row = triangle[i];
        // cout<<endl;
        for(int j = 0; j < row.size(); j++){
            row[j] += min(bottomRow[j], bottomRow[j+1]);
        }
        bottomRow = row;
        // printVector(bottomRow);
    }
    return bottomRow[0];
}

int main(){
    vector<vector<int>> triangle {
        vector<int> {2},
        vector<int> {3, 4},
        vector<int> {6, 5, 7},
        vector<int> {4, 1, 8, 3}
    };
    cout<<minimumTotal(triangle)<<endl;

    return 0;
}