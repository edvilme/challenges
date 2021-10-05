#include <bits/stdc++.h>
using namespace std;


int getDigitsSquared(int n){
    int sum = 0;
    sum += (n % 10)*(n % 10);
    if( floor(n/10) >= 1 ) sum += getDigitsSquared( floor(n/10) );
    return sum;
}

set<int> visited;

bool isHappy(int n){
    int squaredDigits = getDigitsSquared(n);
    while(true){
        if( squaredDigits == 1 ) return true;
        if( visited.find(squaredDigits) != visited.end() ) return false;
        visited.insert(squaredDigits);
        squaredDigits = getDigitsSquared(squaredDigits);
    }
    return false;
}

int main(){
    cout << isHappy(19) << endl;
    cout << isHappy(2) << endl;
    cout << isHappy(13) << endl;
    return 0;
}