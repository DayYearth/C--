/*
Consider a money system consisting of n coins.
Each coin has a positive integer value.
Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,...,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
Constraints

1 <= n <= 100
1 <= x <= 10^6
1 <= c_i <= 10^6

Example
Input:
3 11
1 5 7

Output:
3
*/
#include<bits/stdc++.h>

using namespace std;
#define maxn 105

int c[maxn];

int solve(int c[], int n, int x){
    if(x < 1) return -1;
    if(n < 1) return -1;
    int res = 0; // luu tong hien tai
    for(int i = 1; i <= n; i++){
        res += solve(c,n,x-c[i]);
        cout << res << " ";
    }
    return res;
}

int main(){
    int n; //the number of coins
    int x;  //the desired sum of money
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> c[i];
    cout << solve(c,n,x);
    return 0;
}
