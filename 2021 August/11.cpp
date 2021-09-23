/**
 * @author   : envifly 
 * @Date     : 11/08/2021
 * @Time     : Wednesday Aug 11, 2021 12:25:07 Eastern Daylight Time
 * https://atcoder.jp/contests/abc194/tasks/abc194_c
 */
 
#include <bits/stdc++.h>
using namespace std;
 
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
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};

 
void doStuff(){
	vector<ll> occur(401,0LL);
	int n; cin>>n;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		occur[a+200]++;
	}
	ll ans = 0;
	for(int i = 0; i < 400; i++){
		for(int j = i+1; j < 401; j++){
			ans += occur[i] * occur[j] * abs((j-i) * (j-i));
		}
	}
	
	print(ans);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    
    return 0;
}
 
// you should actually read the stuff at the bottom and not submit the same wrong code
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* maybe just stop being dumb lol
*/
 
