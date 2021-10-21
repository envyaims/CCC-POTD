#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    vector<int> nums = {a,b,c};
    sort(nums.begin(),nums.end());
    a = nums[0], b = nums[1], c = nums[2];
    int apos = b-d, cpos = b+d;
    cout<< max(0,a-apos) + max(0,cpos-c);
    
}
