// Author: envy <3 uwu
// Problem: E - Permutation
// Attempted: 2021-12-28 13:31:11 EST
#pragma GCC optimize (Ofast)
#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
typedef long long ll;
#define vt vector
#define pb push_back
#define ins insert
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define F first
#define S second
#define cont continue
#define SZ(x) (int)x.size()
#define pf printf
#define retf return false
#define rett return true

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i,a,b) for (int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for (int i = (a); i > (b); --i)
#define ROFE(i,a,b) for (int i = (a); i >= (b); --i)
#define trav(a,x) for (auto& a: x)
#define rv(x) trav(i,x)cin>>i;

template<class T> using maxpq = priority_queue<T>;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

const int MOD = 1e9+7;

void solve(){
	int n,m; cin>>n>>m;
	vt<vt<int>> cond(n+1,vt<int>(n+1,1e9));
	FOR(i,0,m){
		int x,y,z; cin>>x>>y>>z;
		ckmin(cond[x][--y],z);
	}
	
	vt<int> pre(n);
	FOR(i,0,n){
		pre[i] = 1<<i;
	}
	
	ll up = 1<<n;
	vt<ll> dp(up);
	dp[0] = 1;
	FOR(i,1,up){
		int alr = __builtin_popcountll(i);
		int cnt = 0;
		bool ok = true;
		ll add = 0;
		FOR(j,0,n){
			if(i&pre[j])cnt++;
			if(cnt > cond[alr][j]){
				ok = false;
				break;
			}
			add += dp[i^pre[j]];
		}
		if(ok)dp[i] += add;
	} 
	pf("%lld",dp[up-1]);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	
}
