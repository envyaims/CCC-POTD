#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
char grid[10][10];
int ngrid[10][10];
bool flashed[10][10];
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};

int ans = 0;
int n = 10;

void simflash(int i,int j){
	for(int k = 0; k < 8; k++){
			int r = dx[k]+i;
			int c = dy[k]+j;
			if(r < 0 || r >= n || c < 0 || c >= n)continue;
			ngrid[r][c]++;
			if(ngrid[r][c] > 9 && !flashed[r][c]){
				ans++;
				flashed[r][c] = true;
				simflash(r,c);
			}
		}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>grid[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ngrid[i][j] = grid[i][j] - '0';
		}
	}
	for(int step =0; step < 100; step++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				ngrid[i][j]++;
				flashed[i][j] = false;
				
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(ngrid[i][j] > 9 && !flashed[i][j]){
					ans++;
					flashed[i][j] = true;
					simflash(i,j);
				}
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(flashed[i][j])ngrid[i][j] = 0;
			}
		}
	}
	cout<<ans;
	
	
}
