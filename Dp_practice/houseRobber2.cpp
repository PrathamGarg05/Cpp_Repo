#include<bits/stdc++.h>
using namespace std;

int dp[105];
int n;
int f(vector<int>& nums, int i){
    if(i==nums.size()-1) return dp[i] = nums[i];
    if(i==nums.size()-2) return dp[i] = max(nums[i],nums[i+1]);
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(nums[i] + f(nums,i+2), 0 + f(nums,i+1));
}
int fbu(vector<int>& nums){
    dp[nums.size()-1] = nums[nums.size()-1];
    dp[nums.size()-2] = max(nums[nums.size()-1],nums[nums.size()-2]);
    for(int i=nums.size()-3;i>=0;i--){
        dp[i] = max(nums[i] + dp[i+2], 0 + dp[i+1]);
    }
    return dp[0];
}
int rob(vector<int>& nums) {
    // memset(dp, -1, sizeof dp);
    n = nums.size();
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    vector<int> first(n-1), last(n-1);
    for(int i=0;i<n-1;i++){
        first[i] = nums[i];
        last[i] = nums[i+1];
    }
    int ans1 = fbu(first);
    // memset(dp, -1, sizeof dp);
    int ans2 = fbu(last);
    return max(ans1,ans2);
}