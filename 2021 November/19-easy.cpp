// Author: envy
// Problem: A. Remainder
// Attempted: 2021-11-19 19:00:35 EST

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
	int n, x, y; cin>>n>>x>>y;
	string s; cin>>s;
	reverse(s.begin(),s.end());
	int ans = 0;
	for(int i = 0; i < x; i++){
		if(s[i] == '1' && i != y){
			s[i] = '0';
			ans++;
		}
		
	}
	if(s[y] == '0'){
		s[y] = '1';
		ans++;
	}
	
	cout<<ans;
	
}
