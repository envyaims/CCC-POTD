#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
template<typename T>
vector<string> split(T str, char sep){
	vector<string> output;
	size_t start = 0, end = 0;
	while((end = str.find(sep,start)) != string::npos){
		if(end != start)output.push_back(str.substr(start,end-start));
		start = end+1;
	}
	
	if(end != start)output.push_back(str.substr(start));
	return output;
	
}

bool check(vector<vector<bool>>& board){
	for(int i = 0; i < 5; i++){
		int cnt = 0;
		for(int j = 0; j < 5; j++){
			if(board[i][j])cnt++;
		}
		if(cnt==5)return true;
	}
	for(int i = 0; i < 5; i++){
		int cnt = 0;
		for(int j = 0; j < 5; j++){
			if(board[j][i])cnt++;
		}
		if(cnt==5)return true;
	}
	int cnt = 0;
	for(int i = 0; i < 5; i++){
		if(board[i][i])cnt++;
	}
	if(cnt==5)return true;
	cnt = 0;
	for(int i=0;i<5;i++){
		if(board[i][4-i])cnt++;
	}
	if(cnt==5)return true;
	return false;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s; cin>>s;
	vector<string> inp = split(s,',');
	vector<vector<vector<int>>> boards;
	while(1){
		if(cin.eof())break;
		vector<vector<int>> curr(5,vector<int>(5));
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				cin>>curr[i][j];
			}
		}
		boards.push_back(curr);
		
	}
	vector<vector<vector<bool>>> won(boards.size(),vector<vector<bool>>(5,vector<bool>(5)));
	for(string i: inp){
		int in = stoi(i);
		for(int j=0;j<boards.size();j++){
			for(int a = 0;a<5;a++){
				for(int b=0;b<5;b++){
					if(boards[j][a][b] == in){
						won[j][a][b] = true;
					}
				}
			}
			if(check(won[j])){
				int cnt = 0;
			for(int a = 0;a<5;a++){
				for(int b=0;b<5;b++){
					//cout<<won[j][a][b];
					if(!won[j][a][b]){
						cnt += boards[j][a][b];
					}
				}
				
				}
				cout<<cnt*in<<"\n";
				return 0;
	 		}
		}
	}
	
}
