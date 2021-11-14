// Author: envy
// Problem: E - Mex Min from AtCoder - AtCoder Beginner Contest 194
// URL: https://atcoder.jp/contests/abc194/tasks/abc194_e
// Limits: 4000 ms, 1024 MB
// Attempted: 2021-11-14 13:16:49 EST

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
	int n,m; cin>>n>>m;
	vector<int> nums(n);
	for(int& i: nums) cin>>i;
	vector<int> mex(n-m+1);
	vector<int> have(n+1);
	for(int i = n-1; i >= n-m; i--){
		have[nums[i]]++;
	}
	for(int i = 0; i <= n; i++){
		if(!have[i]){
			mex[n-m] = i;
			break;
		}
	}
	for(int i = n-m-1; i >= 0; i--){
		have[nums[i+m]]--;
		have[nums[i]]++;
		if(have[nums[i+m]]){
			mex[i] = n;
		}
		else mex[i] = nums[i+m];
		
		if(!have[mex[i+1]]){
			mex[i] = min(mex[i+1],mex[i]);
		}
		
	}
	debug(mex);
	cout<<*min_element(mex.begin(),mex.end());
	
	
}
