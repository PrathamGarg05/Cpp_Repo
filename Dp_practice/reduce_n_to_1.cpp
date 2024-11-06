#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;
vector<ll> dp;
ll f(ll i)
{
    if (i == 1)
        return dp[i] = 0;
    if (i == 2 or i == 3)
        return dp[i] = 1;
    if (dp[i] != -1)
        return dp[i];
    ll ans = LONG_LONG_MAX;
    ans = min(ans, (i % 3 == 0) ? f(i / 3) : INT_MAX);
    ans = min(ans, (i % 2 == 0) ? f(i / 2) : INT_MAX);
    ans = min(ans, f(i - 1));
    return dp[i] = 1 + ans;
}
// int fbu(){
//     dp[1] = 0;
//     dp[2] = dp[3] = 1;

// }
int main()
{
    cout << "enter :";
    cin >> n;
    dp.resize(n + 1, -1);
    cout << f(n);
}