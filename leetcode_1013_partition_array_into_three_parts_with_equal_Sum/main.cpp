#include <bits/stdc++.h>
using namespace std;

int selectUntilSum(int i, int sum, vector<int> arr){
    int accum = 0;
    for(i; i < arr.size(); i++){
        accum += arr[i];
        if(accum == sum) return i;
    }
    return -1;
}

void printVectorInRange(vector<int> arr, int i, int j){
    cout << "[";
    for(i; i <= j; i++){
        cout << arr[i];
        if(i != j) cout<<", ";
    }
    cout << "]";
}


bool canThreePartsEqualSum(vector<int> arr) {
    int sumOfAll = 0;
    for(int &element : arr) sumOfAll += element;
    if(sumOfAll % 3 != 0) return false;
    
    int firstIndex = selectUntilSum(0, sumOfAll/3, arr);
    if(firstIndex == -1 || firstIndex >= arr.size() -2) return false;
    // printVectorInRange(arr, 0, firstIndex);

    int secondIndex = selectUntilSum(firstIndex+1, sumOfAll/3, arr);
    if(secondIndex == -1 || secondIndex >= arr.size() - 1) return false;
    // printVectorInRange(arr, firstIndex+1, secondIndex);
    
    int thirdIndex = selectUntilSum(secondIndex + 1, sumOfAll/3, arr);
    if(thirdIndex == -1 || thirdIndex >= arr.size()) return false;
    // printVectorInRange(arr, secondIndex+1, thirdIndex);

    return true;
}

int main(){
    cout<<canThreePartsEqualSum(vector<int>{ 0,2,1,-6,6,-7,9,1,2,0,1 })<<endl;
    cout<<canThreePartsEqualSum(vector<int>{ 0,2,1,-6,6,7,9,-1,2,0,1 })<<endl;
    cout<<canThreePartsEqualSum(vector<int>{ 3,3,6,5,-2,2,5,1,-9,4 })<<endl;
    cout<<canThreePartsEqualSum(vector<int>{ 0,0,0,0 })<<endl;
    cout<<canThreePartsEqualSum(vector<int>{ 12,-4,16,-5,9,-3,3,8,0 })<<endl;
    return 0;
}