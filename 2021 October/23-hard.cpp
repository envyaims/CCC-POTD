// Author: envy
// Problem: E - Multiplication 4 from AtCoder - AtCoder Beginner Contest 173
// URL: https://atcoder.jp/contests/abc173/tasks/abc173_e
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-10-23 19:06:28 EST

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
	
	int n,k; cin>>n>>k;
	vector<int> nums(n,1);
	for(int i = 0; i < n; i++){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());
	int l = 0, r = n-1;
	int ans = 1;
	bool allnegative = false;
	if(k % 2 == 1){
		ans = nums[r];
		r--;
		k--;
		if(ans < 0){
			allnegative = true;
		}
	}
	for(k; k > 0; k -= 2){
		int right = nums[r] * nums[r-1];
		int left = nums[l] * nums[l+1];
		if(allnegative){
			ans *= right % MOD;
			ans %= MOD;
			r -= 2;
		}
		else{
			if(right >= left){
				ans *= right % MOD;
				ans %= MOD;
				r -= 2;
			}
			else{
				ans *= left % MOD;
				ans %= MOD;
				l += 2;
			}
		}
	}
	cout<<(ans + MOD) % MOD<<endl;
	
}
