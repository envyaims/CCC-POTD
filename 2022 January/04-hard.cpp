// Author: envy <3 uwu
// Problem: C. Bottom-Tier Reversals
// Attempted: 2022-01-04 21:38:38 EST

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
	vt<int> a(n+1);
	FORE(i,1,n){
		cin>>a[i];
	}
	FORE(i,1,n){
		if(a[i]%2 != i%2){
			pf("%d\n",-1);
			return;
		}
	}
	
	vt<int> ans;
	
	auto flip = [&](int x){
		reverse(a.begin()+1,a.begin()+x+1);
		ans.pb(x);
	};
	
	int cnt = 0;
	
	auto doit = [&](int ev, int odd){
		int pos = distance(a.begin(),find(all(a),odd));
		flip(pos);
		pos = distance(a.begin(),find(all(a),ev));
		flip(pos-1);
		pos = distance(a.begin(),find(all(a),ev));
		flip(pos+1);
		flip(3);
		flip(n-cnt);
		
	};
	
	for(int i = n; i >= 3; i-=2){
		doit(i-1,i);
		cnt += 2;
	}
	pf("%d\n",ans.size());
	trav(i,ans){
		pf("%d ",i);
	}
	pf("\n");
	
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
cin>>t;
	while(t--){
		solve();
	}
	
}
