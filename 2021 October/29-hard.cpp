// Author: envy
// Problem: C - Multiple Sequences from AtCoder - AtCoder Regular Contest 116
// URL: https://atcoder.jp/contests/arc116/tasks/arc116_c
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-10-29 18:07:28 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
const int MOD = 998244353;
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

vector<int> facts = {1,1};
vector<int> inverse;

int ncr(int n, int k){
   return facts[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}

map<int,int> primefactorize(int n){
	map<int,int> factors;
	while(n % 2 == 0){
		factors[2]++;
		n /= 2;
	}
	for(int i = 3; i <= sqrt(n); i += 2){
		while(n % i == 0){
			factors[i]++;
			n /= i;
		}
	}
	if(n > 2){
		factors[n]++;
	}
	return factors;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;

	inverse.resize(400001);
	inverse[0] = 1;
    inverse[1] = 1;
    for(int i = 2; i <= 400000; i++){
        facts.push_back(facts.back() * i % MOD);
        inverse[i] = pow(facts.back(),MOD-2,MOD);
    }
	int ans = 0;
	for(int i = 1; i <= m; i++){
		map<int,int> factors = primefactorize(i);
		int cnt = 1;
		for(auto j: factors){
			int q_i = j.second;
			cnt *= ncr(n+q_i-1,n-1);
			cnt %= MOD;
		}
		ans += cnt;
		ans %= MOD;
	}
	cout<<ans;
	
	
}
