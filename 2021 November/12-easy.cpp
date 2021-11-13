// Author: envy
// Attempted: 2021-11-12 12:09:00 EST

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
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		int ntar = b/a;
		int sis = b % a;
		cout<<ntar * ntar * (a-sis) + (ntar+1) * (ntar+1) * sis<<endl;
	}
	
}
