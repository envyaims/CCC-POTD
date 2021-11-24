#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long

int getsum(int x){
	vector<int> f;
	for(int i = 1; i <= sqrt(x); i++){
		if(x % i == 0){
			f.push_back(i);
			if(x/i != i){
				f.push_back(x/i);
			}
		}
	}
	int sum = 0;
	for(int i: f){
		sum += 10*i;
	}
	return sum;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i = 1; 
	while(i++){
		int a = getsum(i);
		if(a >= 36000000){
			cout<<i;
			break;
		}
	}
	
}
