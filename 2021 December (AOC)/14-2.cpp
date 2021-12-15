#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
map<string,string> ins;
string s; 
map<char,int> occ;
map<pair<char,char>,int> subocc;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    while(1){
        if(cin.eof())break;
        string a,b,c; cin>>a>>b>>c;
        ins[a] = c;
    }
    
    for(char i: s){
        occ[i]++;
    }
    for(int i = 0; i < s.size()-1; i++){
    	subocc[{s[i],s[i+1]}]++;
    }
    
    for(int i = 0; i < 40; i++){
    	map<pair<char,char>,int> temp;
    	for(auto j: ins){
    		temp[{j.first[0],j.second[0]}] += subocc[{j.first[0],j.first[1]}];
    		temp[{j.second[0],j.first[1]}] += subocc[{j.first[0],j.first[1]}];
    		occ[j.second[0]] += subocc[{j.first[0],j.first[1]}];
    	}
    	subocc = temp;
    }
    int maxn = 0, minn = 2e18;
    for(auto i: occ){
    	maxn = max(maxn,i.second);
    	minn = min(minn,i.second);
    }
    printf("%lld",maxn-minn);
}
