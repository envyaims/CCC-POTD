#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<string>> patterns, outputs;
	while(1){
		if(cin.eof())break;
		vector<string> pattern(10), output(4);
		for(int i = 0; i < 10; i++){
			cin>>pattern[i];
		}
		string deli; cin>>deli;
		for(int i = 0; i < 4; i++){
			cin>>output[i];
		}
		patterns.push_back(pattern);
		outputs.push_back(output);
	}
	
	int n = patterns.size();
	int ans = 0;
	for(int i = 0; i < n; i++){
		map<int,int> occ;
		for(int j = 0; j < 10; j++){
			occ[patterns[i][j].length()]++;
		}
		for(int j = 0; j < 4; j++){
			if(occ[outputs[i][j].length()]==1)ans++;
		}
		
	}
	cout<<ans;
	
}
