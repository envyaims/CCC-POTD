// Author: envy
// Attempted: 2021-11-15 08:01:58 EST

#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c; cin>>a>>b>>c;
	a = abs(a);
	b = abs(b);
	if(c < (a+b)){
		cout<<"No";
		return 0;
	}
	c -= (a+b);
	debug(c);
	cout<<(c%2==0 ? "Yes" : "No");
	
	
}
