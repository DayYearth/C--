/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 <= n <= 10^6

Example
Input:
3

Output:
4
*/
#include<bits/stdc++.h>

using namespace std;
#define maxn 1000005
#define MOD 1000000007
int f[maxn]; // day luu tong
int main(){
    int n;
    cin >> n;

    f[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(j <= i)
                // gia su f[10] = f[9] + f[8] + f[7] + ... + f[4]
                // neu xuc ra tong 9 thi can xuc ra 1 => f[i-j]
                f[i] = (f[i] + f[i-j]) % MOD;
        }
    }
    cout << f[n];
    return 0;
}
