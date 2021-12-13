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
vector<pair<int,int>> pts;
vector<pair<string,int>> folds;

void yfold(int am){
	for(auto& i: pts){
		if(i.second > am){
			int diff = i.second - am;
			i.second = am - diff;
		}
	}
}

void xfold(int am){
	for(auto& i: pts){
		if(i.first > am){
			int diff = i.first - am;
			i.first = am - diff;
		}
	}
}
int vis(){
	set<pair<int,int>> cur(pts.begin(),pts.end());
	return cur.size();
	
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		if(cin.eof())break;
		string s; cin>>s;
		if(isdigit(s[0])){
			//is coordinate
			vector<string> ps = split(s,',');
			pts.push_back({stoi(ps[0]),stoi(ps[1])});
		}
		else{
			// is instruction
			cin>>s>>s;
			vector<string> ps = split(s,'=');
			folds.push_back({ps[0],stoi(ps[1])});
		}
	}
	for(int i = 0; i < 1; i++){
		string dir = folds[i].first;
		int am = folds[i].second;
		xfold(am);
		cout<<vis();
	}
	
}
