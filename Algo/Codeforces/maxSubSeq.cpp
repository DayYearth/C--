#include <bits/stdc++.h>

using namespace std;
#define maxn 10005

int n;
int a[maxn];

// Giai bang Divive and Conquer

int maximum(int a, int b){
	if(a>b) return a;
	return b;
}

// tinh tong lon nhat o ben trai
int MaxLeft(int l, int r){
	int MaxL = a[l];
	int sum = 0;
	for(int i = l; i <= r; i++){
		sum += a[i];
		MaxL = maximum(sum, MaxL);
	}
	return MaxL;
}

// tinh tong lon nhat o ben phai
int MaxRight(int l, int r){
	int MaxR = a[l];
	int sum = 0;
	for(int i = l; i <= r; i++){
		sum += a[i];
		MaxR = maximum(sum, MaxR);
	}
	return MaxR;
}

int MaxSubsequence(int l, int r){
	if(l == r) return a[l];
	int mid = (l+r)/2;
	
	int WL = MaxSubsequence(l, mid); // tinh trong so cua doan con lon nhat ben trai
	int WR = MaxSubsequence(mid+1, r); // tinh trong so cua doan con lon nhat ben phai
	
	int ML = MaxLeft(l, mid);
	int MR = MaxRight(mid+1, r);	
	int WM = ML + MR;
	
	return maximum(maximum(WL,WR),WM);
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = MaxSubsequence(1,n);
	cout << ans;
	return 0;
}
