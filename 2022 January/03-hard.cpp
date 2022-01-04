// Author: envy <3 uwu
// Problem: C - ThREE
// Attempted: 2022-01-03 19:39:01 EST

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

vector<int> graph[200001];
int n;
vt<int> red, blue;

void dfs(int no, int p, bool col){
	if(col)red.pb(no);
	else blue.pb(no);
	
	trav(i,graph[no]){
		if(i != p)dfs(i,no,!col);
	}
}

void solve(){
	cin>>n;
	FOR(i,0,n-1){
		int u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	
	dfs(1,0,0);
	if(SZ(red) < SZ(blue)){
		swap(red,blue);
	}
	vt<int> nums;
	int blues = SZ(blue);
	int idx = 0;
	vt<int> ans(n+1);
	if(blues <= n/3){
		FORE(i,1,n){
			if(i%3==0){
				nums.pb(i);
			}
		}
		FORE(i,1,n){
			if(i%3!=0){
				nums.pb(i);
			}
		}
	}
	else{
		FORE(i,1,n){
			if(i%3==1){
				nums.pb(i);
			}
		}
		FORE(i,1,n){
			if(i%3==0){
				nums.pb(i);
			}
		}
		FORE(i,1,n){
			if(i%3==2){
				nums.pb(i);
			}
		}
		
	}
	trav(i,blue){
		ans[i] = nums[idx++];
	}
	trav(i,red){
		ans[i] = nums[idx++];

	}
	
	FORE(i,1,n){
		cout<<ans[i]<<" ";
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
