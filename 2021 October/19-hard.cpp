// Problem: C. Pythagorean Triples
// Contest: Codeforces - Codeforces Round #368 (Div. 2)
// URL: https://codeforces.com/problemset/problem/707/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-10-19 14:09:47 EST

#ifndef LOCAL
#include <bits/stdc++.h>
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#endif

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << #__VA_ARGS__ << ":", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using namespace std;
template<typename T> void max_self(T& a, T b){a = max(a,b);}
template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;
using secondpq = priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond>;
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
#define double long double
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

void doStuff(){
	int n; cin>>n;
	if(n <= 2){
		print(-1);
		return;
	}
	
	n % 2 == 1 ? cout<<(n*n -1)/2<<" "<<(n*n+1)/2 : cout<<(n*n/4-1)<<" "<<(n*n/4+1);
	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t  = 1; 
	//cin>>t;
	while(t--){
		doStuff();
	}
    
    
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* maybe just stop being dumb lol
*/
