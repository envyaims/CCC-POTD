// Author: envy
// Problem: D - Xor Sum 4 from AtCoder - AtCoder Beginner Contest 147
// URL: https://atcoder.jp/contests/abc147/tasks/abc147_d
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-11-01 18:55:33 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
const int MOD = 1e9+7;
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<int> nums(n);
	for(int& i: nums)cin>>i;
	int ans = 0;
	for(int i = 0; i <= 60; i++){
		int x = 0, y = 0;
		for(int j = 0; j < n; j++){
			int c = nums[j]>>i;
			c & 1 ? x++ :y++;
		}
		ans += x*y % MOD*pow(2,i,MOD);
		ans %= MOD;
	}
	cout<<ans;
	
}
