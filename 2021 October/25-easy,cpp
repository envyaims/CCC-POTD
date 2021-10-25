// Author: envy
// Problem: B - Intersection from AtCoder - AtCoder Beginner Contest 199（Sponsored by Panasonic）
// URL: https://atcoder.jp/contests/abc199/tasks/abc199_b
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-10-25 17:45:42 EST

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
	int l = -1e9, r = 1e9;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		l = max(l,a);
	}
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		r = min(r,a);
	}
	cout<<max(0LL,r-l+1);
	
}
