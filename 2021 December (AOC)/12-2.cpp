#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
vector<int> graph[100001];
map<string,int> id;
int idcnt = 3;

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
int dp[100001];
int visited[10001];
bool isbig[100001];
int now = 3;

void dfs(int node, bool rep = false){
	dp[node]++;
		for(int i: graph[node]){
			if(isbig[i]){
			dfs(i,rep);
		}
		else if(!rep && visited[i] == 1 && !isbig[i] && i != 1 && i != 2){
			visited[i]++;
			repped[i] = true;
			dfs(i,true);
		}
		else if(!visited[i] && !isbig[i]){
			visited[i]++;
			dfs(i,rep);
		}
	}
	visited[node]--;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	id["start"] = 1;
	id["end"] = 2;
	while(1){
		if(cin.eof())break;
		string s; cin>>s;
		vector<string> sep = split(s,'-');
		if(id[sep[0]] == 0){
			id[sep[0]] = idcnt;
			if(isupper(sep[0][0])){
				isbig[idcnt] = true;
			}
			idcnt++;
		}
		if(id[sep[1]] == 0){
			id[sep[1]] = idcnt;
			if(isupper(sep[1][0])){
				isbig[idcnt] = true;
			}
			idcnt++;
		}
		int a = id[sep[0]];
		int b = id[sep[1]];
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	visited[1]++;
	//dp[1] = 1;
	dfs(1,false);

	cout<<dp[2];
	
}
