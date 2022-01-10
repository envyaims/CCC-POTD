// Author: envy
// Attempted: 2022-01-10 12:15:59 EST

#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<int> nums(n);
	for(int& i: nums)cin>>i;
	int k; cin>>k;
	for(int i = 1; i < n; i++)nums[i] += nums[i-1];
	int ans = k/nums[n-1]*n;
	int rest = k%nums[n-1]+1;
	if(rest > nums[n-1]){
		ans += n+1;
	}
	else{
		ans += lower_bound(nums.begin(),nums.end(),rest) - nums.begin()+1;
	}
	cout<<ans;
	
}
