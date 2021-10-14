// https://codeforces.com/contest/965/submission/131982224
#include <iostream>
#include <cmath>
using namespace std;
long long k,n,s,p;

bool check(long long x){
	long long sheets = x*p;
	long long sheetsneeded = ceil(1.0*n/s);
	return sheets >= sheetsneeded*k;
}
int main(){
	cin>>k>>n>>s>>p;
	
	long long start = 0, end = 1e9;
	while(start < end-1){
		long long mid = start + (end-start)/2;
		if(check(mid)){
			end = mid;
		}
		else start = mid;
	}
	cout<<end;
	
}
