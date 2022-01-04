// Author: envy <3 uwu
// Problem: C1. Balanced Removals (Easier)
// Attempted: 2022-01-02 20:00:36 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
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
#define read(x) trav(i,x)cin>>i;

template<class T> using maxpq = priority_queue<T>;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};
const int MOD = 1e9+7;

void solve(){
	int n; cin>>n;
	vt<array<int,4>> pts(n);
	FOR(i,0,n){
		cin>>pts[i][0]>>pts[i][1]>>pts[i][2];
		pts[i][3] = i+1;
	}
	
	sort(all(pts));
	vt<bool> used(n);
	FOR(i,0,n-1){
		if(!used[i] && pts[i][0] == pts[i+1][0] && pts[i][1] == pts[i+1][1]){
			used[i] = true;
			used[i+1] = true;
			pf("%d %d\n",pts[i][3],pts[i+1][3]);
		}
	}
	
	vt<array<int,4>> can;
	FOR(i,0,n){
		if(!used[i]){
			can.pb(pts[i]);
		}
	}
	
	fill(all(used),false);
	
	FOR(i,0,SZ(can)-1){
		if(!used[i] && can[i][0] == can[i+1][0]){
			used[i] = true;
			used[i+1] = true;
			pf("%d %d\n",can[i][3],can[i+1][3]);
		}
	}
	
	vt<array<int,4>> final;
	FOR(i,0,SZ(can)){
		if(!used[i]){
			final.pb(can[i]);
		}
	}
	
	for(int i = 0; i < SZ(final); i += 2){
		pf("%d %d\n",final[i][3],final[i+1][3]);
	}

	
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin>>t;
	while(t--){
		solve();
	}
	
}
