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
	string s; cin>>s;
	map<string,string> ins;
	while(1){
		if(cin.eof())break;
		string a,b,c; cin>>a>>b>>c;
		ins[a] = c;
	}
	for(int i = 0; i < 10; i++){
		string cur = "";
		for(int j = 0; j < s.size(); j++){
			cur += s[j];
			if(cur.size() >= 2 ){
				string sub = cur.substr(cur.size()-2);
				if(ins.count(sub)){
					cur.erase(cur.begin()+cur.size()-1);
					cur += ins[sub];
					cur += sub[1];
				}
			}
		}
		s = cur;
	}
	int maxc = 0, minc = 1e9;
	for(char c =  'A'; c <= 'Z'; c++){
		int cnt = count(s.begin(),s.end(),c);
		if(cnt == 0)continue;
		maxc = max(maxc,cnt);
		minc = min(minc,cnt);
	}
	cout<<maxc-minc;
	
}
