/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
*/
#include <bits/stdc++.h>

using namespace std;

// hash table
void solution(vector<int>& nums, int target){
    unordered_map<int,int> mp;
    int n = nums.size()-1;
    vector<int> ans;

    // tao hash table
    for(int i = 0; i <= n; ++i){
        mp[nums[i]] = i;
    }

    // solve
    for(int i = 0; i <= n; ++i){
        int tmp = target - nums[i];
        if(mp.count(tmp) && mp[tmp]!= i){
            ans.push_back(i);
            ans.push_back(mp[tmp]);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}


int main(){
    int n; // size cua vector
    cin >> n;
    vector<int> v;
    int target;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> target;
    solution(v, target);
    return 0;
}
