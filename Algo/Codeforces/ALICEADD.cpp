#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	while(a.length() < b.length()) a = a + "0";
	while(a.length() > b.length()) b = b + "0";
	string ans;
	for(int i = a.size(); i >= 0; i--){
		int k = 0;
		int tmp = int(a[i]) + int(b[i]) + k;
		if(tmp >= 10){
			k = 1;
			ans[i] = (tmp-10) - '0'; 
			cout << ans[i] << " ";
		} else k = 0;
		if(k == 1){
			tmp++;
			k = 0;
			if(tmp >= 10) k = 1;
		}
		
	}
}
