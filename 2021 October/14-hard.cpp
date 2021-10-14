// Author: envy
// Problem: D. Remove One Element from Codeforces - Codeforces Round #605 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1272/D#
// Limits: 2000 ms, 256 MB
// Attempted: 2021-10-14 17:48:41 EST

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
typedef long long ll; const ll INF = 1e18; const int MOD = 1e9+7;
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

void doStuff(){
	int n; cin>>n;
	vector<int> nums(n);
	for(int& i: nums)cin>>i;
	vector<int> now(n), sofar(n), numconsec(n);
	now[0] = sofar[0] = 1;
	for(int i = 1; i < n; i++){
		if(nums[i] > nums[i-1]){
			now[i] = now[i-1]+1;
		}
		else now[i] = 1;
		sofar[i] = max(sofar[i-1],now[i]);
	}
	
	numconsec[n-1] = now[n-1];
	for(int i = n-1; i > 0; i--){
		if(now[i] > now[i-1]){
			numconsec[i-1] = numconsec[i];
		}
		else{
			numconsec[i-1] = now[i-1];
		}
	}
	
	debug(now);
	debug(sofar);
	debug(numconsec);
	int ans = sofar[n-1];
	for(int i = 0; i < n-2; i++){
		if(now[i+2] == 1 and nums[i+2] > nums[i]){
			ans = max(ans,now[i] + numconsec[i+2]);
			debug(i,ans);
		}
		else if(now[i+2] == 2 and nums[i+2] > nums[i]){
			ans = max(ans, now[i] + numconsec[i+2]-1);
		}
	}
	print(ans);
	
	
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
