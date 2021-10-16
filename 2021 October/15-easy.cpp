#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
#define print(x) cout<<x<<endl

int n;

main(){
	int t; cin>>t;
	while(t--){
		cin>>n;
		if(n % 2 == 0){
			if(n == 2){
				print(1);
				continue;
			}
			print(2);
		}
		else{
			if(n == 1){
				print(0);
			}
			else if(n == 3){
				print(2);
			}
			else print(3);
		}
		
	}
}
