#include<bits/stdc++.h>
using namespace std;

#define ll long long int


ll minOperations(ll number){
    vector<ll> dp(number+1, 1e9);
    
    dp[0] = 0;

    for(ll i=1; i<=number; i++){
        ll temp = i;

        while(temp > 0){
            ll dig = temp%10;
            dp[i] = min(dp[i], 1 + dp[i-dig]);
            temp/=10;
        }
    }

    return dp[number];
}


int main(){
    ll number;
    cin >> number;

    cout << minOperations(number);


    return 0;
}
