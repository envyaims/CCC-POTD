// Problem: A. Road To Zero
// Contest: Codeforces - Educational Codeforces Round 86 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1342/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;

const int INF = 2e5+10, MOD = 1e9+7;
#define all(x) x.begin(), x.end() // for vectors, etc
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<endl
#define print(x) cout<<x<<endl
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())


void solve(){
	ll n;
	cin>>n;
	for(ll test = 0; test < n; test++){
		ll x,y,a,b;
		cin>>x>>y>>a>>b;
		ll spend = 0;
		spend += (max(x,y) - min(x,y)) * a;
		if(b < 2*a){
			spend += min(x,y) * b;
		}
		else{
			spend += min(x,y) * (2 * a);
		}
		cout<<spend<<endl;
		
		
	}
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    

    return 0;
}
