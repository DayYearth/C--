#include <bits/stdc++.h>

using namespace std;

int f[100];
int f1[100]; // fibo theo de quy co nho

int fibo(int n){
	if(n <= 1) return 1;
	if(f1[n] != -1) return f1[n];
	f1[n] = fibo(n-1) + fibo(n-2);
	return f1[n];
}

int main(){
	f[0] = f[1] = 1;
	int n;
	cin >> n;
	for(int i = 2; i < n; i++){
		f[i] = f[i-1] + f[i-2];
		cout << f[i] << " ";
	}
	cout << "\n";
	
	for(int i = 0; i <= n; i++) f1[i] = -1;
	cout << fibo(n-1);
	return 0;
}
