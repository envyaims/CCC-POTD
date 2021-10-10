// Author: envy
// Problem: D - Small Multiple from AtCoder - AtCoder Regular Contest 084
// URL: https://atcoder.jp/contests/arc084/tasks/arc084_b
// Limits: 2000 ms, 256 MB
// Attempted: 2021-10-09 20:02:02 EST

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
const int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
#define int long long
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

void doStuff(){
	int n; cin>>n;
	vector<int> dist(n+1,INF);
	dist[1] = 1;
	deque<int> q;
	q.push_front(1);
	while(!q.empty()){
		int node = q.front();
		q.pop_front();
		for(auto i: {mp((node*10 )% n, 0), mp((node+1) % n,1)}){
			int curr = i.F;
			int cost = i.S;
			if(dist[node] + cost < dist[curr]){
				dist[curr] = dist[node] + cost;
				if(cost == 1){
					q.push_back(curr);
				}
				else q.push_front(curr);
			}
		}
	}
	print(dist[0]);
		
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
