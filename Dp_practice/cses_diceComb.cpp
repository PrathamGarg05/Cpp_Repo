#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n;
vector<int> dp;

int f(int n){
    if(n==0) return 1;
    if(dp[n] != -1) return dp[n];
    int count = 0;
    for(int i=1;i<=6;i++){
        if(n-i >= 0){
            count = count % MOD + f(n-i) % MOD;
        }
    }
    return dp[n] = count % MOD;
}

int fbu(int num){
    dp[0] = 1;
    for(int n=1;n<=num;n++){
        int count = 0;
        for (int i = 1; i <= 6; i++)
        {
            if (n - i >= 0)
            {
                count = count % MOD + dp[n - i] % MOD;
            }
        }
        dp[n] = count % MOD;
    }
    return dp[num];
}
int main(){
    cin>>n;
    dp.resize(1000005,-1);
    cout<<fbu(n);
}