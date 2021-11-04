// Author: envy
// Problem: D - Xor Sum 2 from AtCoder - AtCoder Regular Contest 098
// URL: https://atcoder.jp/contests/arc098/tasks/arc098_b
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-11-03 21:25:58 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<int> nums(n);
	for(int& i: nums)cin>>i;
	
	vector<int> right(20,-1);
	int bad = -1;
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 20; j++){
			if((nums[i]>>j)&1){
				bad = max(bad,right[j]);
				right[j] = i;
			}
		}
		ans += i-bad;
	}
	cout<<ans;
	
	
	
}
