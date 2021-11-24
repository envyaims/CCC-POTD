// Author: envy
// Attempted: 2021-11-23 07:48:59 EST

#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long

void tc(){
	int a,b,x,y,n; cin>>a>>b>>x>>y>>n;
	int aminus = min(a-x,n);
	int tempn = n;
	tempn -= aminus;
	int bminus = min(b-y, tempn);
	int ansone = (a-aminus) * (b-bminus);
	bminus = min(b-y,n);
	n -= bminus;
	aminus = min(a-x,n);
	int anstwo = (a-aminus) * (b-bminus);
	cout<<min(anstwo,ansone)<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		tc();
	}
	
}
