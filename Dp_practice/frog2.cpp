#include<bits/stdc++.h>
using namespace std;

vector<int> h;
int dp[100005];
int n,k;

int f(int i){
    if(i==n-1) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int j=i+1;j<=i+k;j++){
        if(j<n){
            ans=min(ans,f(j)+abs(h[i]-h[j]));
        }
    }
    return dp[i] = ans;
}
int fbu(){
    dp[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        int ans=INT_MAX;
        for(int j=i+1;j<=i+k;j++){
            if(j<n){
                ans=min(ans,dp[j]+abs(h[i]-h[j]));
            }
        }
        dp[i] = ans;
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