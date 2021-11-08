// Author: envy
// Attempted: 2021-11-08 14:12:08 EST

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
	int n,k; cin>>n>>k;
	string bits = bitset<32>(n).to_string();
	vector<int> ans;
	int power = 1;
	for(int i = 31; i >= 0; i--){
		if(bits[i] == '1'){
			ans.push_back(power);
		}
		power *= 2;
	}
	if(ans.size() > k){
		cout<<"NO";
		return 0;
	}
	
	int total = __builtin_popcount(n);
	while(total < k){
		debug(ans);
		vector<int> newans;
		for(int i = 0; i < ans.size(); i++){
			if(total < k and ans[i]/2 > 0){
					total++;
					for(int j = 0; j < 2; j++){
						newans.push_back(ans[i]/2);
					}
				}
			else{
				newans.push_back(ans[i]);
			}
		}
		if(ans == newans){
			break;
		}
		ans = newans;
	}
	if(ans.size() != k){
		cout<<"NO";
	}
	else{
		cout<<"YES"<<endl;
		for(int i: ans){
			cout<<i<<" ";
		}
	}
	
}
