#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m; cin>>n>>m;
	char grid[n][m];
	pair<int,int> startat;
	queue<pair<int,int>> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>grid[i][j];
			if(grid[i][j] == 'E'){
				q.push({i,j});
			}
			else if(grid[i][j] == 'S'){
				startat = {i,j};
			}
		}
	}
	
	vector<vector<int>> dist(n,vector<int>(m,1e9));
	dist[q.front().first][q.front().second] = 0;
	
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		for(int i = 0 ;i < 4; i++){
			int newr = dx[i] + top.first;
			int newc = dy[i] + top.second;
			if(newr < 0 || newr >= n || newc < 0 || newc >= m || dist[newr][newc] != 1e9 || grid[newr][newc] == 'T')continue;
			dist[newr][newc] = dist[top.first][top.second]+1;
			q.push({newr,newc});
		}
	}
	
	int sdist = dist[startat.first][startat.second];
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j=0;  j                             < m; j++){
			if(grid[i][j] > '0' && grid[i][j] <= '9' && dist[i][j] <= sdist){
				ans += grid[i][j] - '0';
			}
		}			
	}
	cout<<ans;
}
