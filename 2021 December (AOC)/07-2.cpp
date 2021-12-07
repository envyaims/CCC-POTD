#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
template<typename T>
vector<string> split(T str, char sep){
	vector<string> output;
	size_t start = 0, end = 0;
	while((end = str.find(sep,start)) != string::npos){
		if(end != start)output.push_back(str.substr(start,end-start));
		start = end+1;
	}
	
	if(end != start)output.push_back(str.substr(start));
	return output;
	
}

int fuel = 1e18;

void check(vector<int>& nums, int pos){
	int cur = 0;
	for(int i: nums){
		int now = abs(i-pos);
		cur += now * (now+1)/2;
	}
	fuel = min(fuel,cur);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s; cin>>s;
	vector<string> ps = split(s,',');
	vector<int> nums;
	for(string i: ps){
		nums.push_back(stoi(i));
	}
	for(int i = 0; i <= 3000; i++){
		check(nums,i);
	}
	cout<<fuel;
}
