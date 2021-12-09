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
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			bool ok = true;
			for(int k = 0; k < 4; k++){
				int r = dx[k]+i, c = dy[k]+j;
				if(r < 0 || r >= n || c < 0 || c >= m)continue;
				if(grid[i][j]-'0' >= grid[r][c]-'0')ok = false;
			}
			if(ok){
				ans += grid[i][j]-'0';
				ans++;
			}
		}
	}
	cout<<ans;
	
}
