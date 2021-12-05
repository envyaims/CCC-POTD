#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
#define int long long
int cnt[1000][1000];
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
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		if(cin.eof())break;
		string a,b,c; cin>>a>>b>>c;
		vector<string> pa = split(a,','),  pb = split(c,',');
		if(pa[0] == pb[0]){
			int apos = stoi(pa[1]), bpos = stoi(pb[1]);
			for(int j = min(apos,bpos);j <= max(apos,bpos);j++){
				cnt[stoi(pa[0])][j]++;
			}
		}
		else if(pa[1] == pb[1]){
			int apos = stoi(pa[0]), bpos = stoi(pb[0]);
			for(int j = min(apos,bpos); j <= max(apos,bpos); j++){
				cnt[j][stoi(pa[1])]++;
			}
		}
		else{
			
		}
	}
	int ans = 0;
	for(int i = 0; i< 1000; i++){
		for(int j = 0; j < 1000; j++){
			if(cnt[i][j]>1)ans++;
		}
	}
	cout<<ans;
	
}
