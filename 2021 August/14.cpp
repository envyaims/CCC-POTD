// Problem: A. Hexadecimal's theorem
// Contest: Codeforces - Codeforces Round #125 (Div. 2)
// URL: https://codeforces.com/problemset/problem/199/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-08-14 13:14:22 EST

#include <bits/stdc++.h>
using namespace std;

inline namespace fastio {
	const int BSZ = 1<<15; 
	char ibuf[BSZ]; int ipos, ilen;
	char nc() {
		if (ipos == ilen) {
			ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);
			if (!ilen) return EOF;
		}
		return ibuf[ipos++];
	}
	template<class T> void ri(T& x) { // read int or ll
		char ch; int sgn = 1;
		while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
		x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
		x *= sgn;
	}
	template<class T> void rc(T& x){ // read char
		x = nc();
		while(isspace(x)){
			x = nc();
		}
	}
	template<class T, class... Ts> void ri(T& t, Ts&... ts) { 
		ri(t); ri(ts...); } // read ints
	template<class str>void rs(str& x) { // read str
		char ch; while (isspace(ch = nc()));
		do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);
	}
}

typedef long long ll;
const ll INF = 1e18;
const int MOD = 1e9+7, MN = 1e5 + 5;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};

vector<ll> fibo;
ll n;

void recur(int now){
	ll cur = fibo[now-1] + fibo[now-2];
	if(cur == n){
		return;
	}
	fibo.pb(cur);
	recur(now+1);
	
}


void doStuff(){
	ri(n);
	if(n == 0){
		print("0 0 0");
		return;
	}
	fibo.pb(0);
	fibo.pb(1);
	recur(2);
	int siz = sz(fibo);
	cout<<fibo[siz-1]<<" "<<fibo[siz-2]<<" "<<0;
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
	// int t; ri(t);
	// while(t--){
		// doStuff();
	// }
    
    return 0;
}

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* maybe just stop being dumb lol
*/
