// https://codeforces.com/contest/1509/problem/A

#include <bits/stdc++.h>
using namespace std;

bool cs(int a, int b){
	return (a%2) < (b%2);
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> stuff(n);
		for(int& i: stuff)cin>>i;
		sort(stuff.begin(),stuff.end(),cs);
		for(int i: stuff)
			cout<<i<<" ";
		cout<<endl;
	}
	
	
	
}
