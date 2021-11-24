#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(){
  int n; cin>>n;
  vector<pair<int,int>> nums(n);
  int minx = 1e18, maxx = -1e18, miny = 1e18, maxy = -1e18;
  for(int i =0; i < n; i++){
    cin>>nums[i].first>>nums[i].second;
    minx = min(minx,nums[i].first);
    miny = min(miny,nums[i].second);
    maxx = max(maxx,nums[i].first);
    maxy = max(maxy,nums[i].second);
    }

  cout<<max(0LL,maxx - miny)<<endl;

}

signed main(){
  int t; cin>>t;
  while(t--){
    test_case();
  }
}
