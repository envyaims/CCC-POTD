//  https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1/
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    vector<int> prefix(n+1,0);;
	    for(int i = 0; i < n; i++){
	        prefix[i+1] = arr[i] + prefix[i];
	    }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = n; j >= i; j--){
                if(j - i+1 <= ans)break;
                if((prefix[j] - prefix[i-1]) % k == 0){
                    ans = max(ans,j-i+1);
                    break;
                }
            }
        }
        return ans;
        
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends
