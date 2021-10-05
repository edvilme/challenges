#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    for(int &e : v) cout << e << " ";
}

int trap(vector<int> height){
    int sum = 0;

    vector<int> largestLeft(height.size()),
        largestRight(height.size());

    int largestLeftValue = 0,
        largestRightValue = 0;
    
    for(int i = 0; i < height.size(); i++){
        int j = height.size() - 1 - i;
        // Left values
        largestLeft[i] = largestLeftValue;
        if(height[i] > largestLeftValue) largestLeftValue = height[i];
        // Right values
        largestRight[j] = largestRightValue;
        if(height[j] > largestRightValue) largestRightValue = height[j];
        // Get min between both
    }
    for(int i = 0; i < height.size(); i++){
        // sum += min(largestLeft[])
        int h = min(largestLeft[i], largestRight[i]) - height[i];
        if(h < 0) h = 0;
        sum += h;
    }
    return sum;
}

int main(){
    cout<<trap(vector<int>{0,1,0,2,1,0,1,3,2,1,2,1})<<endl;
    cout<<trap(vector<int>{4,2,0,3,2,5})<<endl;
    return 0;
}