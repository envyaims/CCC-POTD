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
	vector<int> nums;
	while(1){
		if(cin.eof())break;
		int a; cin>>a;
		nums.push_back(a);
	}
	int ans = 0;
	for(int i = 0; i < nums.size()-3; i++){
		if(nums[i] + nums[i+1] + nums[i+2] < nums[i+1] + nums[i+2] + nums[i+3])ans++;
	}
	cout<<ans;
	
}
