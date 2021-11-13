// Author: envy
// Problem: C. Product 1 Modulo N from Codeforces - Codeforces Round #716 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1514/C
// Limits: 1000 ms, 256 MB
// Attempted: 2021-11-12 19:47:17 EST

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
	vector<int> nums = {1};
	int multiply = 1;
	for(int i = 2; i <= n-1; i++){
		if(gcd(i,n) == 1){
			nums.push_back(i);
			multiply *= i;
			multiply %= n;
		}
	}
	if(multiply != 1){
		nums.pop_back();
	}
	cout<<nums.size()<<endl;
	for(int i: nums){
		cout<<i<<" ";
	}
}
