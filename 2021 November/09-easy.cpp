// Author: envy
// Attempted: 2021-11-09 07:45:18 EST

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
	int n; cin>>n;
	n--;
	if(n == 0){
		cout<<1<<"\n";
		return;
	}
	while(n++){
		string s = to_string(n);
		bool can  = true;
		for(char i: s){
			if(i != '0' && n % (i - '0') != 0){
				can  = false;
				break;
			}
		}
		if(can){
			cout<<n<<"\n";
			return;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		tc();
	}
	
}
