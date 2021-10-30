// Author: envy
// Problem: E - Logs from AtCoder - AtCoder Beginner Contest 174
// URL: https://atcoder.jp/contests/abc174/tasks/abc174_e
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-10-30 12:22:33 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
int n,k;
vector<int> logs;

bool check(int x){
	int opsneeded = 0;
	for(int i = 0; i < n; i++){
		if(logs[i] > x){
			opsneeded += logs[i]/x;
		}
	}
	return opsneeded <= k;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	logs.resize(n);
	for(int& i: logs)cin>>i;
	int l = 0, r = 1e20;
	while(l < r-1){
		int mid = (l+r)/2;
		if(check(mid)){
			r = mid;
		}
		else l = mid;
	}
	cout<<r;
	
}
