#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long

char notin(string a, string b){
	vector<int> ans;
	for(char i: a){
		if(b.find(i) == string::npos){
			ans.push_back(i);
		}
	}
	if(ans.empty() || ans.size() > 1)return 'x';
	return ans[0];
}

string merge(string a, char b){
	a.push_back(b);
	return a;
}

string mergetwo(string a, char b, char c){
	a.push_back(b);
	a.push_back(c);
	return a;
}
main(){
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
	
	vector<vector<int>> lights(10);
	lights[2] = {1,3,4,5,7};
	lights[3] = {1,3,4,6,7};
	lights[5] = {1,2,4,6,7};
	lights[6] = {1,2,4,5,6,7};
	lights[9] = {1,2,3,4,6,7};
	lights[0] = {1,2,3,5,6,7};
	
	lights[1] = {3,6};
	lights[4] = {2,3,4,6};
	lights[7] = {1,3,6};
	lights[8] = {1,2,3,4,5,6,7};
	
	// 1 & 7 gives 1
	// 9 & 4 with character 1 gives 7
	// 3 & 7 with characters 7 gives 4
	// 9 & 7 with char(4) + char(7) gives 2
	// 9 & 5 gives 3
		
	
	// we now know
	// 1 4 7 8 9 3 5 6
	
	
	
	
	
	int n = patterns.size();
	int ans = 0;
	for(int i = 0; i < n; i++){
		map<int,vector<string>> lens;
		for(int j = 0; j < 10; j++){
			lens[patterns[i][j].length()].push_back(patterns[i][j]);
		}
		map<int,char> charpos;
		vector<string> def(10);
		def[1] = lens[2][0];
		def[4] = lens[4][0];
		def[7] = lens[3][0];
		def[8] = lens[7][0];
		charpos[1] = notin(def[7], def[1]);
		
		for(string j: lens[6]){
			char cur = notin(j,merge(def[4],charpos[1]));
			if(cur != 'x'){
				def[9] = j;
				charpos[7] = cur;
				break;
			}
		}
		for(string j: lens[5]){
			char cur = notin(j,merge(def[7],charpos[7]));
			if(cur != 'x'){
				def[3] = j;
				charpos[4] = cur;
				break;
			}
		}
		charpos[2] = notin(def[9],mergetwo(def[7],charpos[4],charpos[7]));
		
		for(string j: lens[5]){
			if(j == def[3])continue;
			char cur = notin(def[9],j);
			if(cur != 'x'){
				def[5] = j;
				charpos[3] = cur;
				break;
			}
		}
		
		for(string j: lens[6]){
			if(notin(def[8],j) == charpos[3]){
				def[6] = j;
				break;
			}
		}
		
		for(string j: lens[6]){
			if(notin(def[8],j) == charpos[4]){
				def[0] = j;
				break;
			}
		}
		
		for(string j: patterns[i]){
			if(find(def.begin(),def.end(),j) == def.end()){
				def[2] = j;
				break;
			}
		}
		
		for(string& j: def){
			sort(j.begin(),j.end());
		}
		string currans = "";
		for(string& j: outputs[i]){
			sort(j.begin(),j.end());
			int idx = find(def.begin(),def.end(),j) - def.begin();
			currans += to_string(idx);
		}
		ans += stoi(currans);
		
		
	}
	cout<<ans;
}
