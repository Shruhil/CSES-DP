#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = 1e9+7;

bool isValid(int r, int c, int n){
    if(r < 0 || r>=n || c<0 || c>=n) return false;

    return true;
}

ll solveRec(vector<vector<char>> &grid, ll row, ll col, ll n){
    if(row==n-1 && col==n-1) return 1;

    if(isValid(row, col, n) == false || grid[row][col]=='*') return 0;

    
    ll right_paths = solveRec(grid, row, col+1, n);
    ll down_paths = solveRec(grid, row+1, col, n);

    return (right_paths + down_paths)%mod;
}

ll solveMem(vector<vector<char>> &grid, ll row, ll col, ll n, vector<vector<ll>> &dp){
    if(!isValid(row, col, n) || grid[row][col]=='*') return 0;
    if(row==n-1 && col==n-1) return 1;
    
    if(dp[row][col]!=-1) return dp[row][col];

    ll right_paths = solveMem(grid, row, col+1, n, dp);
    ll down_paths = solveMem(grid, row+1, col, n, dp);

    return dp[row][col] = (right_paths + down_paths)%mod;
}

ll solveTab(vector<vector<char>> &grid, ll n){
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

    dp[n-1][n-1] = 1;

    for(ll row = n-1; row>=0; row--){
        for(ll col=n-1; col>=0; col--){
            if((row==n-1 && col==n-1) || (grid[row][col]=='*')) continue;
            
            ll right_paths = dp[row][col+1];
            ll down_paths = dp[row+1][col];

            dp[row][col] = (right_paths + down_paths)%mod;
        }
    }

    return dp[0][0];
}


ll solveOpt(vector<vector<char>> &grid, ll n){
    vector<ll> curr(n+1, 0);
    vector<ll> next(n+1, 0);

    curr[n-1] = 1;

    for(ll row = n-1; row>=0; row--){
        for(ll col=n-1; col>=0; col--){
            if((row==n-1 && col==n-1) || (grid[row][col]=='*')) continue;
            
            ll right_paths = curr[col+1];
            ll down_paths = next[col];

            curr[col] = (right_paths + down_paths)%mod;
        }
        next = curr;
    }

    return next[0];
}

ll  numberPathsPossible(vector<vector<char>> &grid, ll n){
    // return solveRec(grid, 0, 0, n);

    // vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
    // return solveMem(grid, 0, 0, n, dp);

    if(grid[n-1][n-1]=='*') return 0;

    // return solveTab(grid, n);

    return solveOpt(grid, n);
}


int main(){
    ll n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> grid[i][j];
        }
    }

    cout << numberPathsPossible(grid, n);

    return 0;
}