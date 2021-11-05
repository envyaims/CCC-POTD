// Author: envy
// Problem: E - Queen on Grid from AtCoder - AtCoder Beginner Contest 183
// URL: https://atcoder.jp/contests/abc183/tasks/abc183_e
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-11-05 18:58:22 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
const int MOD = 1e9+7;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin>>n>>m;
	vector<vector<char>> grid(n,vector<char>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>grid[i][j];
		}
	}
	vector<vector<int>> dp(n,vector<int>(m));
	vector<vector<int>> left(n, vector<int>(m)), up(n,vector<int>(m)), diag(n, vector<int>(m));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == '#')continue;
			if(j > 0){
				left[i][j] = left[i][j-1] + dp[i][j-1];
				left[i][j] %= MOD;
				dp[i][j] += left[i][j];
				dp[i][j] %= MOD;
			}
			if(i > 0){
				up[i][j] = up[i-1][j] + dp[i-1][j];
				up[i][j] %= MOD;
				dp[i][j] += up[i][j];
				dp[i][j] %= MOD;
			}
			if(i > 0 and j > 0){
				diag[i][j] = diag[i-1][j-1] + dp[i-1][j-1];
				diag[i][j] %= MOD;
				dp[i][j] += diag[i][j];
				dp[i][j] %= MOD;
			}
			
			// for(int k = i-1; k >= 0 && grid[k][j] != '#'; k--){
				// dp[i][j] += dp[k][j];
				// dp[i][j] %= MOD;
			// }
			// for(int k = j-1; k >= 0 and grid[i][k] != '#'; k--){
				// dp[i][j] += dp[i][k];
				// dp[i][j] %= MOD;
			// }
			// for(int r = i-1, c = j-1; r >= 0 and c >= 0 and grid[r][c] != '#'; r--, c--){
				// dp[i][j] += dp[r][c];
				// dp[i][j] %= MOD;
			// }
		}
	}
	debug(dp);
	cout<<dp[n-1][m-1];
	
}
