#include <bits/stdc++.h>

using namespace std;
const long long modulo = 1e9+7;

long long solve(long long a, long long b){ // b = k, a = n
	if(b > a) return 0;
	if(b == a || b == 0) return 1;
	if(b == 1) return a;
	long long ans = solve(a-1, b-1)+solve(a-1, b) % modulo;
	return ans;
}

int main(){
	long long n, k;
	cin >> n >> k;
	cout << solve(k,n);
	return 0;
}
