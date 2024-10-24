#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> h;
int dp[100005];
int f(int i){
    if(i==n-1) return 0;
    if(dp[i] != -1) return dp[i];
    int res = INT_MAX;
    for(int j=i+1;j<=i+k;j++){
        if(j >= n) continue;
        res = min(res, abs(h[i]-h[j]) + f(j));
    }
    return dp[i] = res;
}
int fbu(){
    dp[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        int res = INT_MAX;
        for(int j=i+1;j<=i+k;j++){
            if(j >= n) continue;
            res = min(res, abs(h[i]-h[j]) + dp[j]);
        }
        dp[i] = res;
    }
    return dp[0];
}
int main(){
    cin>>n>>k;
    h.clear();
    h.resize(n);
    // memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<fbu()<<endl;
}