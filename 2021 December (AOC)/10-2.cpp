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
	pts['('] = 1;
	pts['[']= 2;
	pts['{'] = 3;
	pts['<'] = 4;
	
	map<char,char> rev;
	rev[')'] = '(';
	rev[']'] = '[';
	rev['}'] = '{';
	rev['>'] = '<';
	
	vector<int> anses;
	
	while(1){
		if(cin.eof())break;
		string s; cin>>s;
		vector<char> q;
		bool ok = true;
		for(char i: s){
			if(rev.count(i)){
				if(q.back() == rev[i]){
					q.pop_back();
				}
				else{
					ok = false;
					break;
				}
			}
			else q.push_back(i);
		}
		int ans = 0;
		reverse(q.begin(),q.end());
		if(ok){
			for(char i: q){
				ans *= 5;
				ans += pts[i];
			}
			anses.push_back(ans);
		}
		
		
		
	}
	sort(anses.begin(),anses.end());
	cout<<anses[anses.size()/2];
		

	
}
