// Author: envy
// Problem: C. Ayoub and Lost Array from Codeforces - Codeforces Round #533 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1105/C#
// Limits: 1000 ms, 256 MB
// Attempted: 2021-10-12 20:48:20 EST

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
	int n,l,r; cin>>n>>l>>r;
	vector<int> mod(3, (r-l)/3);
	if(r % 3 >= l % 3){
		for(int i = l % 3; i <= r % 3; i++){
			mod[i]++;
	    }
	}
	else{
		for(int i = l % 3; i <= r % 3 + 3; i++){
			mod[i%3]++;
		}
	}

	

	
	debug(l % 3, r % 3);
	debug(mod);
	
	// vector<int> mods(3, 0);
	// for(int i = l; i <= r; i++){
		// mods[i % 3]++;
	// }
	// debug(mods);
	
	vector<vector<int>> dp(n+1,vector<int>(3));
	for(int i = 0; i < 3; i++){
		dp[1][i] = mod[i];
	}
	for(int i = 1; i < n; i++){
		dp[i+1][0] = (dp[i][0] * mod[0] % MOD) + (dp[i][1] * mod[2] % MOD) + (dp[i][2] * mod[1] % MOD);
		dp[i+1][1] = (dp[i][0] * mod[1] % MOD ) + (dp[i][1] * mod[0] % MOD) + (dp[i][2] * mod[2] % MOD);
		dp[i+1][2] = (dp[i][0] * mod[2] % MOD) + (dp[i][1] * mod[1] % MOD) + (dp[i][2] * mod[0] % MOD);
	}
	print(dp[n][0] % MOD);
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
