// Author: envy <3 uwu
// Problem: E - Swap
// Attempted: 2021-12-26 18:33:35 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
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
#define rv(x) trav(i,x)cin>>i;

template<class T> using maxpq = priority_queue<T>;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

const int MOD = 1e9+7;

int dp[31][6420][31][31];

void solve(){
	string s; cin>>s;
	int x; cin>>x;
	int n = SZ(s);
	ckmin(x,435LL);
	
	vt<int> kpos,epos,ypos;
	FOR(i,0,n){
		if(s[i] == 'K')kpos.pb(i);
		if(s[i] == 'E')epos.pb(i);
		if(s[i] == 'Y')ypos.pb(i);
	}
	
	auto btw = [&](int h, int l, vector<int>& v){
		int cnt = 0;
		FOR(i,0,l){
			if(v[i] > h){
				cnt++;
			}
		}
		return cnt;
	};
	
	dp[0][0][0][0] = 1; // empty string
	FORE(i,0,n-1){
		// i == length-1 or current index
		FORE(k,0,SZ(kpos)){
			// used the first k Ks
			FORE(e,0,SZ(epos)){
				if(k+e > i)continue;
				// used the first e Es
				int y = i-k-e;
				if(y > SZ(ypos))continue;
				FORE(ops,0,x){
					// done "ops" operations
					if(k < SZ(kpos)){
						// add a fucking k rn i swear to fuck
						int pos = kpos[k];
						int posdif = btw(pos,y,ypos) + btw(pos,e,epos)-i+pos;
						if(ops+posdif <= x)dp[i+1][ops+posdif][k+1][e] += dp[i][ops][k][e];
						
					}
					if(e < SZ(epos)){
						// add an e kill me already
						int pos = epos[e];
						int posdif = btw(pos,k,kpos) + btw(pos,y,ypos)-i+pos;
						if(ops+posdif <= x)dp[i+1][ops+posdif][k][e+1] += dp[i][ops][k][e];
					}
					
					if(y < SZ(ypos)){
						int pos = ypos[y];
						int posdif = btw(pos,k,kpos) + btw(pos,e,epos)-i+pos;
						if(ops+posdif <= x)dp[i+1][ops+posdif][k][e] += dp[i][ops][k][e];
					}
				}
			}
		}
	}
	
	int ans = 0;
	FORE(j,0,x){
		ans += dp[n][j][SZ(kpos)][SZ(epos)];
	}
	pf("%lld",ans);
	
	
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
