#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// ll findMinCoins(ll n, ll sum, ll *coins){
//     if(sum==0) return 0;
//     if(sum < 0) return 1e9;

//     ll minCoins = 0;

//     for(ll i=0; i<n; ++i){
//         ll coins = 1 + solveRec(n, sum-coins[i], coins);

//         if(coins!=1e9){
//             minCoins = min(minCoins, coins); 
//         }
//     }

//     return minCoins;
// }

ll solveMem(ll n, ll sum, ll *arr, vector<ll> &dp){
    if(sum==0) return 0;
    if(sum < 0) return INT_MAX;

    if(dp[sum]!=-1) return dp[sum];

    ll minCoins = INT_MAX;

    for(ll i=0; i<n; ++i){
        ll coins = 1 + solveMem(n, sum-arr[i], arr, dp);

        if(coins!=INT_MAX){
            minCoins = min(minCoins, coins);
        }
    }

    return dp[sum] = minCoins;
}


ll solveTab(ll n, ll sum, ll* arr){
    vector<ll> dp(sum+1, INT_MAX);
    dp[0] = 0;

    for(ll s = 1; s<=sum; ++s){
        ll minCoins = INT_MAX;

        for(ll i=0; i<n; ++i){
            if(s-arr[i]>=0){
                ll coins = 1 + dp[s-arr[i]];
                if(coins!=INT_MAX){
                    minCoins = min(minCoins, coins);
                }
            }
        }

        dp[s] = minCoins;
    }

    return dp[sum];

}


int main(){
    ll n, sum;
    cin >> n >> sum;

    ll coins[n];

    for(ll i=0; i<n; ++i){
        cin >> coins[i];
    }

    // cout << findMinCoins(n, sum, coins);

    // vector<ll> dp(sum+1, -1);

    // if(solveMem(n, sum, coins, dp)==INT_MAX)  cout << -1;
    // else cout << solveMem(n, sum, coins, dp);


    if(solveTab(n, sum, coins)==INT_MAX) cout << -1;
    else cout << solveTab(n, sum, coins);
    return 0;
}