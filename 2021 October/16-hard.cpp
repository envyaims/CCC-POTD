// Author: envy
// Problem: E - Filters from AtCoder - AtCoder Beginner Contest 196
// URL: https://atcoder.jp/contests/abc196/tasks/abc196_e
// Limits: 2000 ms, 1024 MB
// Attempted: 2021-10-16 09:46:52 EST

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
template<typename T> void max_self(T& a, T b){a = max(a,b);}
template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;
using secondpq = priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll; const ll INF = 2e18; const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define tobin(b,x) bitset<b>(x).to_string()
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};
#define int long long
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

int func(int a, int t, int x){
	if(t == 1){
		return x + a;
	}
	if(t == 2){
		return max(x,a);
	}
	if(t == 3){
		return min(x,a);
	}
}

void doStuff(){
	int n,q; cin>>n;
	vector<int> a(n), t(n);
	for(int i = 0; i < n; i++){
		int x,y; cin>>x>>y;
		a[i] = x;
		t[i] = y;
	}
	cin>>q;
	vector<int> x(q);
	for(int i = 0; i < q; i++){
		cin>>x[i];
	}
	
	int higher = INF, lower = -INF, add = 0;
	for(int i = 0; i < n; i++){
		if(t[i] == 1){
			add += a[i];
			higher += a[i];
			lower += a[i];
		}
		else if(t[i] == 2){
			max_self(lower,a[i]);
			max_self(higher,a[i]);
			
		}
		else if(t[i] == 3){
			min_self(lower,a[i]);
			min_self(higher,a[i]);
		}
	}
	
	debug(higher,lower,add);
	for(int i = 0; i < q; i++){
		if(x[i] + add > higher){
			print(higher);
		}
		else if (x[i] + add < lower){
			print(lower);
		}
		else print(x[i]+add);
		
	}
	
	
	// for(int i = 0; i < q; i++){
		// int prev = func(a[0],t[0],x[i]);
		// for(int j = 1; j < n; j++){
			// prev = func(a[j],t[j],prev);
			// debug(prev);
		// }
		// cerr<<endl;
		// print(prev);
	// }
	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
		doStuff();
	}
}
