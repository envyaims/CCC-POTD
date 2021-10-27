// Author: envy
// Problem: D - Powerful Discount Tickets from AtCoder - AtCoder Beginner Contest 141
// URL: https://atcoder.jp/contests/abc141/tasks/abc141_d
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-10-27 18:08:06 EST

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
	int n,m; cin>>n>>m;
	priority_queue<int> pq;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		pq.push(a);
	}
	while(!pq.empty() && m--){
		int front = pq.top();
		pq.pop();
		front /= 2;
		if(front > 0){
			pq.push(front);
		}
	}
	int ans = 0;
	while(!pq.empty()){
		int front = pq.top();
		pq.pop();
		ans += front;
	}
	cout<<ans;
	
}
