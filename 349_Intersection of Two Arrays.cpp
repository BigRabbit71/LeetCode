class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> results;
        
        if(nums1.empty() || nums2.empty()) return results;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        auto begin1 = nums1.begin(), end1 = nums1.end();
        auto begin2 = nums2.begin(), end2 = nums2.end();
        
        while(begin1!=end1 && begin2!=end2){
            if(*begin1 < *begin2){
                begin1++;
            }else if(*begin2 < *begin1){
                begin2++;
            }else if(*begin1==*begin2){
                if(results.empty() || results.back() != *begin1){
                    results.push_back(*begin1);
                }
                begin1++;
                begin2++;
            }
        }   
        return results;
    }
};