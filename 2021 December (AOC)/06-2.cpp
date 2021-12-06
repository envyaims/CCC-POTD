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
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s; cin>>s;
	vector<string> ps = split(s,',');
	vector<int> fish(9);
	for(string ss: ps){
		fish[stoi(ss)]++;
	}
//	debug(fish);
	for(int i = 1; i <= 256; i++){
		int rem = fish[0];
		for(int j = 1; j <= 8; j++){
			fish[j-1] = fish[j];
		}
		fish[8] = rem;
		fish[6] += rem;
	}
	int ans = 0;
	debug(fish);
	for(int i: fish){
		ans += i;
	}
	cout<<ans;
	
	
	
}
