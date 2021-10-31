// Author: envy
// Problem: B - ABC from AtCoder - AtCoder Grand Contest 034
// URL: https://atcoder.jp/contests/agc034/tasks/agc034_b
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-10-31 10:43:31 EST

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
	string s; cin>>s;
	string newstr = "";
	int n = s.length();
	for(int i = 0; i < n; i++){
		newstr += s[i];
		if(newstr.size() > 2 and newstr.substr(newstr.length()-2) == "BC"){
			newstr = newstr.substr(0,newstr.length()-2) + "D";
		}
	}
	debug(newstr);
	s = newstr;
	int ans =0;
	int acount = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'A'){
			acount++;
		}
		else if(s[i] == 'D'){
			ans += acount;
		}
		else acount = 0;
	}
	cout<<ans;
	
}
