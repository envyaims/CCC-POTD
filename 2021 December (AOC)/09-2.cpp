#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
vector<string> grid;
int n, m;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
bool visited[1000][1000];

void dfs(int r,int c, int& siz){
	if(r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || grid[r][c] == '9')return;
	visited[r][c] = true;
	siz++;
	for(int i = 0; i < 4; i++){
		dfs(r+dx[i],c+dy[i],siz);
	}
	
}
	
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
	int ans = 0;
	vector<int> sizes;
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j] && grid[i][j] != '9'){
				int siz = 0;
				dfs(i,j,siz);
				sizes.push_back(siz);
			}
		}
	}
	sort(sizes.rbegin(),sizes.rend());
	cout<<sizes[0]*sizes[1]*sizes[2];
	
}
