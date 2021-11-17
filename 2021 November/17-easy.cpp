// Author: envy
// Attempted: 2021-11-17 13:32:29 EST

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
	int a,b; cin>>a>>b;
	bool hasfive= false, haseven = false;
	int ans = 1;
	for(int i = a+1; i <= b; i++){
		if(i%5==0)hasfive = true;
		if(i%2==0)haseven = true;
		if(hasfive && haseven){
			cout<<0;
			return 0;
		}
		ans *= i;
		ans %= 10;
	}
	cout<<ans;
	
	
}
