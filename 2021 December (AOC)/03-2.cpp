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
		
		vector<vector<string>> most, least;
		most.push_back(stuff);
		least.push_back(stuff);

		for(int i = 0; i < stuff[0].length(); i++){
			int one = 0, zero = 0;
			for(int j = 0; j < most.back().size(); j++){
				if(most.back()[j][i] == '1')one++;
				else zero++;
			}
			char mostbit, leastbit;
			if(one >= zero)mostbit = '1';
			else mostbit = '0';
			
			one = 0, zero = 0;
			
			for(int j = 0; j < least.back().size(); j++){
				if(least.back()[j][i] == '1')one++;
				else zero++;
			}
			
			if(zero <= one)leastbit = '0';
			else leastbit = '1';
			
			vector<string> tempmost, templeast;
			for(int j = 0; j < most.back().size(); j++){
					if(most.back()[j][i] == mostbit){
						tempmost.push_back(most.back()[j]);
					}
				}
				for(int j = 0; j < least.back().size(); j++){
					if(least.back()[j][i] == leastbit){
						templeast.push_back(least.back()[j]);
					}
				}
			most.push_back(tempmost);
			least.push_back(templeast);
		}
		

		for(string i: most.back())cout<<i;
		cout<<"\n";
		while(least.back().size() == 0){
			least.pop_back();
		}
		for(string i: least.back())cout<<i;
		// i used a binary to decimal converter from here lol
		

	
}
