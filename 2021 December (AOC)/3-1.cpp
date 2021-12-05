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
	vector<string> stuff;
	while(1){
		if(cin.eof())break;
		string a; cin>>a;
		stuff.push_back(a);
		}
		
		string most = "", least = "";
		for(int i = 0; i < stuff[0].length(); i++){
			int one = 0, zero = 0;
			for(int j = 0; j < stuff.size(); j++){
				if(stuff[j][i] == '1')one++;
				else zero++;
			}
			if(one > zero){
				most += "1";
				least += "0";
			}
			else{
				most += "0";
				least += "1";
			}
		}
		cout<<most<<" "<<least;
		// i used a binary to decimal converter from here lol
		

	
}
