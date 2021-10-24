// Author: envy
// Problem: D - Redistribution from AtCoder - AtCoder Beginner Contest 178
// URL: https://atcoder.jp/contests/abc178/tasks/abc178_d
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-10-24 09:03:02 EST

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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin>>n;
	vector<int> dp(n+1,1);
	if(n <= 2){
		cout<<0;
		return 0;
	}
	
	for(int i = 3; i <= n; i++){
		for(int j = 3; j <= i-3; j++){
			dp[i] += dp[i-j];
			dp[i] %= MOD;
		}
	}
	cout<<dp[n] % MOD;
	
}
