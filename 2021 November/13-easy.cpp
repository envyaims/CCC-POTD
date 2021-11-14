#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,p; cin>>n>>m>>k>>p;
	map<string,int> id;
	vector<bool> isinfected(m+1,false);
	int idnow = 1;
	for(int i = 0; i < n; i++){
		string name; cin>>name;
		id[name] = idnow;
		isinfected[idnow] = true;
		idnow++;
	}
	for(int i = 0; i < m; i++){
		string s; cin>>s;
		if(id[s] == 0){
			id[s] = idnow;
			idnow++;
		}
	}
	
	vector<vector<vector<string>>> classes(p+1);
	for(int i = 0; i < k; i++){
		int period, n_i; cin>>period>>n_i;
		vector<string> people(n_i);
		for(int j = 0; j < n_i; j++){
			cin>>people[j];
		}
		classes[period].push_back(people);
	}
	
	vector<int> periods(p+1);
	periods[0] = n;
	for(int i = 1; i <= p; i++){
		int more = 0;
		for(auto x: classes[i]){
			bool can = false;
			for(auto y: x){
				if(isinfected[id[y]]){
					can = true;
					break;
				}
			}
			if(can){
				for(auto y: x){
					if(!isinfected[id[y]]){
						isinfected[id[y]] = true;
						more++;
					}
				}
			}
		}
		periods[i] = periods[i-1] + more;
	}
	
	int q; cin>>q;
	while(q--){
		int q_i; cin>>q_i;
		auto it = lower_bound(periods.begin(),periods.end(),q_i);
		if(it == periods.end()){
			cout<<-69420<<"\n";
		}
		else cout<<it - periods.begin()<<"\n";
	}
	
}
