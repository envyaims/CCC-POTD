// Author: envy
// Problem: F. Interesting Function from Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1538/F
// Limits: 2000 ms, 256 MB
// Attempted: 2021-11-06 08:53:11 EST

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
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		int ans = 0;
		for(;b != 0 || a != 0;){
			ans += b-a;
			b /= 10;
			a /= 10;
		}
		cout<<ans<<endl;
	}
	
}
