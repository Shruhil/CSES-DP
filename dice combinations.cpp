#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
ll mod = 1e9+7;

ll solveRec(ll n){
    if(n<0) return 0;
    if(n==0) return 1;

    ll ans = 0;
    for(int num=1; num<=6; ++num){
        ans+=(solveRec(n-num));
    }

    return ans;
}

ll solveMem(ll n, vector<ll> &dp){
    if(n<0) return 0;
    if(n==0) return 1;

    if(dp[n]!=-1) return dp[n];

    ll ans = 0;
    for(int num=1; num<=6; ++num){
        ans+=(solveMem(n-num, dp));
    }

    return dp[n] = ans%mod;
}

ll solveTab(ll n){
    vector<ll> dp(n+1, 0);
    
    dp[0] = 1;

    for(ll sum = 1; sum<=n; ++sum){
        ll ans = 0;
        for(int num=1; num<=6; ++num){
            if(sum-num>=0){
                ans+=(dp[sum-num])%mod;
            }
        }

        dp[sum] = ans;
    }

    return dp[n]%mod;
}


int main(){
    ll n;
    cin >> n;

    // return solveRec(n);
    // vector<ll> dp(n+1, -1);
    // cout << solveMem(n, dp);

    cout << solveTab(n);

    return 0;
}