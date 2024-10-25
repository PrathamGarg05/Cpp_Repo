#include<bits/stdc++.h>
using namespace std;

int dp[105];
int n;
int f(vector<int>& nums, int i){
    if(i==n-1) return dp[i] = nums[i];
    if(i==n-2) return dp[i] = max(nums[i],nums[i+1]);
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(nums[i] + f(nums,i+2), 0 + f(nums,i+1));
}
int fbu(vector<int>& nums){
    dp[n-1] = nums[n-1];
    dp[n-2] = max(nums[n-1],nums[n-2]);
    for(int i=n-3;i>=0;i--){
        dp[i] = max(nums[i] + dp[i+2], 0 + dp[i+1]);
    }
    return dp[0];
}
int rob(vector<int>& nums) {
    // memset(dp, -1, sizeof dp);
    n = nums.size();
    if(n==1) return nums[0];
    return fbu(nums);
}
