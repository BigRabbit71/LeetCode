class Solution {
public:
    int sub_rob(vector<int>& nums) { 
        int n = nums.size();
        vector<vector<int>> f(n+1, vector<int>(2, 0));
        
        for(int i=1; i<=n; ++i){
            f[i][0] = max(f[i-1][0], f[i-1][1]);
            f[i][1] = f[i-1][0] + nums[i-1];
        }
        
        return max(f[n][0], f[n][1]);
    }
    
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        
        int n = nums.size();
        
        // didn't steal house 0
        vector<int> nums1(n-1);
        auto cur1 = nums.begin()+1;
        while(cur1!=nums.end()){
            nums1.push_back(*cur1);
            ++cur1;
        }
        
        // didn't steal house n-1
        vector<int> nums2(n-1);
        auto cur2 = nums.begin();
        while(cur2!=(nums.end()-1)){
            nums2.push_back(*cur2);
            ++cur2;
        }
        
        return max(sub_rob(nums1), sub_rob(nums2));
    }
};