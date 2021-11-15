// Author: envy
// Attempted: 2021-11-15 11:33:23 EST

#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long

vector<int> graph[500001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i = 0; i < m; i++){
		int n_i; cin>>n_i;
		vector<int> kids(n_i);
		for(int j = 0; j < n_i; j++){
			cin>>kids[j];
		}
		for(int j = 0; j < n_i -1; j++){
			graph[kids[j]].push_back(kids[j+1]);
			graph[kids[j+1]].push_back(kids[j]);
		}
	}
	
	vector<bool> visited(n+1,false);
	vector<int> ans(n+1);
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			visited[i] = true;
			queue<int> q;
			q.push(i);
			vector<int> same = {i};
			while(!q.empty()){
				int kid = q.front();
				q.pop();
				for(int j: graph[kid]){
					if(!visited[j]){
						same.push_back(j);
						visited[j] = true;
						q.push(j);
					}
				}
			}
			for(int i: same){
				ans[i] = same.size();
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout<<ans[i]<<" ";
	}
	
}
