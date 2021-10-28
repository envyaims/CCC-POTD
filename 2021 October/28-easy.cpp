// Author: envy
// Problem: A. Initial Bet from Codeforces - Codeforces Round #273 (Div. 2)
// URL: https://codeforces.com/problemset/problem/478/A
// Limits: 1000 ms, 256 MB
// Attempted: 2021-10-23 14:20:30 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif

using namespace std;
#define int long long

int a,b,c,d,e;

bool check(int x){
	// the start with x
	int more = 0, less = 0;
	for(int i: {a,b,c,d,e}){
		if(i > x){
			more += i-x;
		}
		else{
			less += x-i;
		}
	}
	return less == more;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d>>e;
	for(int i = 1; i <= 100; i++){
		if(check(i)){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	
}
