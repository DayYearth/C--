#include <bits/stdc++.h>

using namespace std;
#define maxn 10005

int x[maxn];
int n;
int visited[maxn] = {0};
int cnt = 0;

void Try(int k){
	for(int v = 1; v <= 9; v++){
		if(visited[v] == 0){
			x[k] = v;
			visited[v] = 1;
			if(k == 7){
				int t = x[1]*100 + x[2]*10 + x[3] - x[7]*100 - 62 + x[4]*1000 + x[5]*100 + x[6]*10 + x[3];
				if(t == n) cnt++;
			} else Try(k+1);
			visited[v] = 0;
		}
	}
}

int main(){
	cin >> n;
	Try(1);
	cout << cnt;
	return 0;
}
