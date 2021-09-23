//  https://leetcode.com/problems/longest-well-performing-interval/ 

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> prefix(n+1,0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + (hours[i] > 8 ? 1 : -1);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(ans > n-i)break;
            for(int j = n; j > i; j--){
                if(prefix[j] > prefix[i]){
                    ans = max(ans,j-i);
                    break;
                }
                if(j-i < ans)break;
            }
        }
        return ans;
        

        
    }
};
