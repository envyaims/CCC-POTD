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
	int x = 0, y = 0;
	while(1){
		if(cin.eof())break;
		string c; int a;
		cin>>c>>a;
		if(c == "forward")x += a;
		else if(c == "down")y += a;
		else y -= a;
	}
	cout<<x*y;
	
}
