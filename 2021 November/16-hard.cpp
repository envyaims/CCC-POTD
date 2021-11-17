// Author: envy
// Problem: A. Row GCD
// Attempted: 2021-11-16 21:02:54 EST

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
	vector<int> a(n), b(m);
	for(int& i: a)cin>>i;
	for(int &i: b)cin>>i;
	int yourmom = 0;
	for(int i = 1; i < n; i++){
		yourmom = gcd(yourmom, a[i] - a[0]);
	}
	for(int i = 0; i < m; i++){
		cout<<gcd(yourmom, b[i] + a[0])<<" ";
	}
	
}
