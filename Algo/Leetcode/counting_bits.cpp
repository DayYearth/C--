/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/
#include <bits/stdc++.h>

using namespace std;

/*
In O(N) Time
Let if we have X and Y in Such a way that,
X/2 = Y
then Number of set bits in X - Number of set bit in Y <= 1

eg let X = 7 and Y = 3
then 7 / 2 = 3;
7 -> 1 1 1 number of set bit are 3
3 -> 0 1 1 number of set bit are 2
there difference is 3 - 2 <= 1

another eg
X = 12 and y = 6
then 12 / 2 = 6;
12 -> 1100 number of set bit are 2
6 -> 0110 number of set bit are 2

there difference is 2 - 2 <= 1

There can be 2 cases
When we have X has Even,
no of set bit in X = no of set bit in Y
and When X is ODD
no of set bit in X = 1 + no of set bit in Y
*/

vector<int> counting(int n){
    vector<int> ans(n+1);
    ans[0] = 0;
    for(int i = 1; i <= n; i++){
        ans[i] = ans[i/2] + (i%2);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> ans = counting(n);
    for(int i = 0; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
