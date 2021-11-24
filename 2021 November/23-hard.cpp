// Author: envy
// Problem: D. Maximum Sum of Products
// Attempted: 2021-11-23 20:37:25 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long

int a[5001], b[5001], prod[5001][5001], prefix[5002];

void ntarsis(int left, int right){
	if(prod[left][right] != 0)return;
	if(left == right){
		prod[left][right] = a[left] * b[right];
	}
	else if(left == right-1){
		prod[left][right] = a[right] * b[left] + a[left] * b[right];
	}
	else{
		ntarsis(left+1,right-1);
		prod[left][right] = a[right] * b[left] + a[left] * b[right] + prod[left+1][right-1];
	}
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}
	
	for(int i = 1; i <= n; i++){
		prefix[i] = prefix[i-1] + a[i-1] * b[i-1];
	}
	int ans = prefix[n];
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			ntarsis(i,j);
			int curr = prod[i][j];
			int rest = prefix[i] + (prefix[n] - prefix[j+1]);
			ans = max(ans,curr+rest);
		}
	}
	cout<<ans<<endl;
	
	
}
