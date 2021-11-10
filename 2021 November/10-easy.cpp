// Author: envy
// Attempted: 2021-11-10 07:47:30 EST

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
	int n; cin>>n;
	vector<pair<int,int>> rects(n);
	for(int i =0; i < n; i++){
		int a,b; cin>>a>>b;
		rects[i] = {a,b};
	}
	if(rects[0].second > rects[0].first){
		swap(rects[0].second,rects[0].first);
	}
	debug(rects);
	for(int i = 1; i < n; i++){
		if(rects[i].first <= rects[i-1].first && rects[i].second <= rects[i-1].first){
			if(rects[i].second > rects[i].first){
				swap(rects[i].second,rects[i].first);
			}
		}
		else if(rects[i].second <= rects[i-1].first){
			swap(rects[i].second,rects[i].first);
		}
		else if(rects[i].first <= rects[i-1].first){
			
		}
		else{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	
}
