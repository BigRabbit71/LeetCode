class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int n = nums.size();
        vector<vector<int>> f(n+1, vector<int>(2, 0));
        
        for(int i=1; i<=n; ++i){
            f[i][0] = max(f[i-1][0], f[i-1][1]);
            f[i][1] = f[i-1][0] + nums[i-1];
        }
        
        return max(f[n][0], f[n][1]);
    }
};