class Solution {
private:
    int result = 0;
    
public:   
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int n = nums.size();
        vector<int> f1(n, 1);    // at least one number
        for(int i=0; i<n; ++i){
            if(i>0 && nums[i-1] < nums[i])
                f1[i] = f1[i-1]+1;
            if(f1[i] > result) 
                result = f1[i];
        }
        
        //Comment for "increasing":
        
//         // reverse
//         reverse(nums.begin(), nums.end());
        
//         vector<int> f2(n, 1);    // at least one number
//         for(int i=0; i<n; ++i){
//             if(i>0 && nums[i-1] < nums[i])
//                 f2[i] = f2[i-1]+1;
//             if(f2[i] > result) 
//                 result = f2[i];
//         }
        
        return result;
    }    
};