#include<bits/stdc++.h>
using namespace std;

int n;
int x;
vector<int> coins;
vector<int> dp;
int f(int x){
    if(x==0) return 0;
    if(dp[x] != -1) return dp[x];
    int ans = INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(x-coins[i] < 0) continue;
        ans = min(ans, f(x-coins[i]));
    }
    if(ans == INT_MAX) return dp[x] = INT_MAX;
    return dp[x] = 1 + ans;
}

int fbu(int num){
    dp[0] = 0;
    for(int x=1;x<=num;x++){
        int ans = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (x - coins[i] < 0)
                continue;
            ans = min(ans, dp[x - coins[i]]);
        }
        if (ans == INT_MAX)
            dp[x] = INT_MAX;
        else dp[x] = 1 + ans;
    }
    if(dp[num] == INT_MAX) return INT_MAX;
    return dp[num];
}
int main(){
    cin>>n>>x;
    coins.resize(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    dp.resize(1000005,-1);
    int ans = fbu(x);
    if(ans == INT_MAX) cout<< -1;
    else cout<<ans;
}