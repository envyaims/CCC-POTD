// https://www.spoj.com/problems/APS/

/**
 * @author   : envifly 
 * @Date     : 10/08/2021
 * @Time     : Tuesday Aug 10, 2021 11:46:58 Eastern Daylight Time
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
vector<ll> sieve(10000001,0);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// doStuff();
	
	sieve[0] = 0;
	sieve[1] = 0;
	for(ll i = 2; i <= 10000000; i++){
		if(sieve[i] == 0){
			sieve[i] = i;
			for(ll j = i*i; j <= 10000000; j += i){
				if(sieve[j] == 0){
					sieve[j] = i;
				}
			}
		}
	}

	/*for(int i = 0; i < 1000; i++){
		cout<<i<<": "<<sieve[i]<<"\n";
	}*/
	vector<ll> bullshit(10000001,0);

	for(int i = 2; i <= 10000000; i++){
		bullshit[i] = bullshit[i-1] + sieve[i];
	}

	ll t; cin>>t;
	 while(t--){
		ll n; cin>>n;
		cout<<bullshit[n]<<"\n";
	}
    
    return 0;
}

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* maybe just stop being dumb lol
*/

