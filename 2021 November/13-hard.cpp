// Author: envy
// Problem: C - Keep Graph Connected from AtCoder - AtCoder Regular Contest 108
// URL: https://atcoder.jp/contests/arc108/tasks/arc108_c
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-11-13 12:57:47 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long

int n,m; 
vector<int> graph[100001];
map<pair<int,int>,int> cost;
vector<int> label(100001,-1);

void dfs(int node){
	for(int i: graph[node]){
		if(label[i] == -1){
			if(label[node] == cost[make_pair(node,i)]){
				int cnt = 1;
				while(cnt == label[node]){
					cnt++;
				}
				label[i] = cnt;
			}
			else label[i] = cost[make_pair(node,i)];
			dfs(i);
		}
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a,b,c; cin>>a>>b>>c;
		cost[make_pair(a,b)] = c;
		cost[make_pair(b,a)] = c;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	label[1] = 1;
	dfs(1);
	
	for(int i = 1; i <= n; i++){
		cout<<label[i]<<endl;
	}
	
	
	
	
}
