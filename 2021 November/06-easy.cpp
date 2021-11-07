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
	int total, maxbones, floors, n; cin>>total>>maxbones>>floors>>n;
	vector<int> days(total+1), fell(total+1);
	for(int i = 0; i < n; i++){
		int day, from, to; cin>>day>>from>>to;
		fell[day] += from-to;
	}
	days[0] = maxbones;
	for(int i = 1; i <= total; i++){
		days[i] = days[i-1];
		days[i] -= fell[i];
		if(days[i] <= 0){
			cout<<i;
			return 0;
		}
		if(fell[i] == 0){
			days[i] = min(days[i]+1,maxbones);
		}
	}
	cout<<-1;
	
}
