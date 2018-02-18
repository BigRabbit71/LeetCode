class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int n = nums.size();
        vector<int> f(n, 1);
        
        for(int j=1; j<n; ++j){
            for(int i=0; i<j; ++i){
                if(nums[i]<nums[j] && (f[i]+1)>f[j]) // important!
                    f[j] = f[i]+1;
            }
        }
        
        int res = INT_MIN;
        for(int i=0; i<n; ++i){
            res = max(res, f[i]);
        }
        
        return res;
    }
};