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
	int n; cin>>n;
	vector<bool> yes(3002,false);
	while(n--){
		int a; cin>>a;
		yes[a] = true;
	}
	for(int i = 1; i <= 3001; i++){
		if(!yes[i]){
			cout<<i;
			return 0;
		}
	}
	
}
