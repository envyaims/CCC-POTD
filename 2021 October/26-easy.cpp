// Problem: B - Visibility
// Contest: AtCoder - AtCoder Beginner Contest 197（Sponsored by Panasonic）
// URL: https://atcoder.jp/contests/abc197/tasks/abc197_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-10-26 07:48:49 EST

#ifndef LOCAL
#include <bits/stdc++.h>
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,x,y; cin>>n>>m>>x>>y;
	vector<string> grid(n);
	for(int i = 0; i < n; i++){
		cin>>grid[i];
	}
	int ans = 0;
	x--; y--;
	for(int i = x-1; i >= 0; i--){
		if(grid[i][y] == '.')ans++;
		else break;
	}
	for(int i = x+1; i < n; i++){
		if(grid[i][y] == '.')ans++;
		else break;
	}
	for(int i = y+1; i < m; i++){
		if(grid[x][i] == '.')ans++;
		else break;
	}
	for(int i = y-1; i >= 0; i--){
		if(grid[x][i] == '.')ans++;
		else break;
	}
	cout<<ans+1;
	
	
}
