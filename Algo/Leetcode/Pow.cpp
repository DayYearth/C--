/*
Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/
#include<bits/stdc++.h>

using namespace std;

// su dung bitwise

void solution(double x, int n){
    double pow = 1;
    if(n < 0){
        x = 1/x;
    }
    if(n == 0) cout << 1;
    int k = abs(n);
    while(k != 0){
        if(k & 1){
            pow = pow * x;
        }
        x *= x;
        k >>=1;
    }
    cout << pow;
}

int main(){
    double x;
    int n;
    cin >> x >> n;
    solution(x, n);
    return 0;
}
