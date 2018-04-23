class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        // case err:
        if(nums.empty()){
            return 0;
        }
        
        // case normal:
        int longestLen = 1;
        //f[j]：以nums[j]为结尾的子序列
        vector<int> f(nums.size(), 1);  
        
        for(int j=0; j<nums.size(); ++j){
            for(int i=0; i<j; ++i){
                if(nums[i] < nums[j]){
                    f[j] = max(f[j], f[i]+1);
                }
            }
        }
        
        // 随着i增大，后面元素的增加，可能会影响前面元素的选取。故要取所有f中max
        for(int i=0; i<f.size(); ++i){
            longestLen = max(f[i], longestLen);
        }
        
        return longestLen;
    }
};