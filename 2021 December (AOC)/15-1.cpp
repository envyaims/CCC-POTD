#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
vector<string> grid;
int n,m;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
int dist[1000][1000];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		if(cin.eof())break;
		string s; cin>>s;
		grid.push_back(s);
	}
	n = grid.size();
	m = grid[0].size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dist[i][j] = 1e9;
		}
	}
	minpq<array<int,3>> pq;
	dist[0][0] = 0;
	pq.push({0,0,0});
	while(!pq.empty()){
		array<int,3> cur = pq.top();
		pq.pop();
		int d = cur[0],  r = cur[1],  c = cur[2];
		if(d > dist[r][c])continue;
		for(int i = 0; i < 4; i++){
			int nr = dx[i]+r, nc = dy[i]+c;
			if(nr < 0 || nr >= n || nc < 0 || nc >= m)continue;
			int nd = d + (grid[nr][nc] - '0');
			if(nd < dist[nr][nc]){
				dist[nr][nc] = nd;
				pq.push({nd,nr,nc});
			}
		}
		
	}
	cout<<dist[n-1][m-1];
	
}
