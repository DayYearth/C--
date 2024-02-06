/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/
#include<bits/stdc++.h>

using namespace std;
#define maxn 1005

int dp[maxn];
int n;
int cost[maxn];

int cost_min(int a, int b){
    if(a < b) return a;
    return b;
}

void solve(){
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2; i < n; i++){
        dp[i] = cost[i] + cost_min(dp[i-1], dp[i-2]);
    }
    cout << cost_min(dp[n-1], dp[n-2]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    solve();
    return 0;
}

/*
int minCostClimbingStairs(int[] cost) {
	int n = cost.length;
	int[] dp = new int[n];
	for (int i=0; i<n; i++) {
		if (i<2) dp[i] = cost[i];
		else dp[i] = cost[i] + Math.min(dp[i-1], dp[i-2]);
	}
	return Math.min(dp[n-1], dp[n-2]);
}

int minCost(int[] cost, int n) {
	if (n < 0) return 0;
	if (n==0 || n==1) return cost[n];
	if (dp[n] != 0) return dp[n];
	dp[n] = cost[n] + Math.min(minCost(cost, n-1), minCost(cost, n-2));
	return dp[n];
}
*/
