#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
vector<ll> dp;

ll f(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    if(dp[n] != -1) return dp[n];
    vector<int> dig;
    int temp = n;
    while(temp){
        dig.push_back(temp % 10);
        temp /= 10;
    }
    ll ans = INT_MAX;
    for(int i=0;i<dig.size();i++){
        if(dig[i] == 0) continue;
        ans = min(ans ,1 + f(n-dig[i]));
    }
    return dp[n] = ans;
}

ll fbu(){
    dp[0] = 0;
    for(int i=1;i<=9;i++){
        dp[i] = 1;
    }
    for(int i=10;i<=n;i++){
        vector<int> dig;
        int temp = i;
        while (temp)
        {
            dig.push_back(temp % 10);
            temp /= 10;
        }
        ll ans = INT_MAX;
        for (int j = 0; j < dig.size(); j++)
        {
            if (dig[j] == 0)
                continue;
            ans = min(ans, 1 + dp[i - dig[j]]);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main(){
    cin>>n;
    dp.clear();
    dp.resize(1000005, -1);
    cout<<fbu();
}