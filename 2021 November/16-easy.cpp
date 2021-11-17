// Author: envy
// Attempted: 2021-11-16 14:43:19 EST

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
	int a,b; cin>>a>>b;
	int alla = a;
	if(a >= b){
		cout<<"YES"<<endl;
		return;
	}
	if(a%2==0){
		a *= 3;
		a /= 2;
		if(a >= b){
			cout<<"YES"<<endl;
			return;
		}
		if(a % 2 == 1)a--;
		if(a > alla){
			cout<<"YES"<<endl;
			return;
		}
	}
	else{
		a--;
		a *= 3;
		a /= 2;
		if(a >= b){
			cout<<"YES"<<endl;
			return;
		}
		if(a % 2 == 1)a--;
		if(a > alla){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t; 
	while(t--){
		tc();
	}
	
}
