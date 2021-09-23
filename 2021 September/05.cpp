// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
auto fastIO = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix(n+1,0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + cardPoints[i];
        }
        if(k == n){
            return prefix[n];
        }
        
        int ans = -1e9+5;
        for(int i = 0; i <= k; i++){
            int sumfromstart = prefix[i];
            int sumfromend = prefix[n] - prefix[n-k+i];
            ans = max(ans,sumfromstart+sumfromend);
        }
        return ans;
    }
};
