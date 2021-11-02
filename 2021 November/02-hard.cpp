// Author: envy
// Problem: E - Handshake from AtCoder - AtCoder Beginner Contest 149
// URL: https://atcoder.jp/contests/abc149/tasks/abc149_e
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-11-02 17:26:13 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
int n,m;
vector<int> nums;
vector<int> prefix;
int finaltotal = -1;
int finalcount = -1;

// ntarsis doesnt know how to solve his own potd be like
bool check(int x){
	int count = 0;
	int totalsum = 0;
	for(int i = 0; i < n; i++){
		auto it = lower_bound(nums.begin(),nums.end(),x-nums[i]);
		if(it != nums.end()){
			int dist = distance(nums.begin(),it);
			count += n-dist;
			totalsum += nums[i] * (n-dist) + prefix[n] - prefix[dist];
		}
	}
	if(count >= m){
		finaltotal = totalsum;
		finalcount = count;
		return true;
	}
	else return false;
	
	
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	nums.resize(n);
	for(int& i:nums)cin>>i;
	sort(nums.begin(),nums.end());
	// sort(nums.begin(),nums.end(),greater<int>());
	prefix.resize(n+1);
	for(int i = 1; i <= n; i++){
		prefix[i] = prefix[i-1] + nums[i-1];
	}
	
	int l = 0, r = 1e9;
	while(l < r-1){
		int mid = l + (r-l)/2;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	debug(finaltotal);
	int ans = finaltotal - (finalcount-m)*l;
	cout<<ans;
	
	
	
	
	
	// i want to kill somoene
}
