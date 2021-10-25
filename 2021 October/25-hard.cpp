// Author: envy
// Problem: E - Double Factorial from AtCoder - AtCoder Beginner Contest 148
// URL: https://atcoder.jp/contests/abc148/tasks/abc148_e
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-10-25 18:31:25 EST

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
	int ans = 0;
	if(n % 2 == 1){
		cout<<0;
		return 0;
	}
	n/=2;
	while(n >= 5){
		n /= 5;
		ans += n;
	}
	cout<<ans;
	
}
