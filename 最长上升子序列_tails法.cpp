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
        // init:
        int longestLen = 1;
        vector<int> tails;
        tails.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] > tails[longestLen-1]){
                // 长度加一，tails往后挪一个
                ++longestLen;
                tails.push_back(nums[i]);
            }
            else{
                // tails维持着递增的性质
                // 所以可以通过二分查找，找到一个大于nums[i]的最小值
                int l = 0, r = tails.size()-1, mid; 
                while(l<r){
                    mid = l + (r-l)/2;
                    if(tails[mid] < nums[i]){
                        // 小于nums[i]的不要，所以+1
                        l = mid+1;
                    }else{
                        r = mid;
                    }
                }
                tails[l] = nums[i];
            }
        }
        
        return longestLen;
    }
};