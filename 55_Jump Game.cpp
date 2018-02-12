class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        
        int n = nums.size();
        vector<bool> f(n, false);   // set false for initial
        
        // init
        f[0] = true;
        
        for(int j=1; j<n; ++j){  
            for(int i=j-1; i>=0; --i){
                // start from (j-1) to save time
                if(f[i] && (i+nums[i])>=j){
                    f[j] = true;
                    break;
                }
            }
        }
        
        return f[n-1];
    }
};