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
	map<char,int> pts;
	pts[')'] = 3;
	pts[']']=57;
	pts['}'] = 1197;
	pts['>'] = 25137;
	
	map<char,char> rev;
	rev[')'] = '(';
	rev[']'] = '[';
	rev['}'] = '{';
	rev['>'] = '<';
	int ans = 0;
	while(1){
		if(cin.eof())break;
		string s; cin>>s;
		vector<char> q;
		for(char i: s){
			if(rev.count(i)){
				if(q.back() == rev[i]){
					q.pop_back();
				}
				else{
					ans += pts[i];
					break;
				}
			}
			else q.push_back(i);
		}
		
		
	}
		
		
	cout<<ans;
	
}
