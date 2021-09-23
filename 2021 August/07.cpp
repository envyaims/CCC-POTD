// Problem: C - Min Difference
// Contest: AtCoder - AtCoder Beginner Contest 212
// URL: https://atcoder.jp/contests/abc212/tasks/abc212_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Input: stdin   
// Output: stdout   
// Attempted: 2021-07-31 08:14:08 EST
 
#include <bits/stdc++.h>
 
// use for debugging
// g++ -std=c++17 -Wshadow -Wall -o a a.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;
 
const int INF = 1e18, MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout<<#x<<" = "<<x<<endl
#define print(x) cout<<x<<endl
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
 
 
void doStuff(){
	int n,m;
	cin>>n>>m;
	ll ans = INF;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; i++)cin>>a[i];
	for(int i = 0; i < m; i++){
		cin>>b[i];
	}
	sort(all(a));
	sort(all(b));
	
	int tempa = 0, tempb = 0;
	
	while(tempa < n && tempb < m){
		ll diff = abs(a[tempa]- b[tempb]) * 1LL;
		if(diff < ans){
			ans = diff;
		}
		if(a[tempa] < b[tempb]){
			tempa++;
		}
		else tempb++;
	}
	
	print(ans);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	doStuff();
    
 
    return 0;
}
