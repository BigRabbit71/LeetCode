class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int diffNum = 1;
		if(nums.size()==0){
			return 0;
		}
		else if(nums.size()==1){
			return 1;
		}
		else{
			for(int i=1; i<nums.size(); i++){
				if(nums[i] != nums[diffNum-1]){
					nums[diffNum] = nums[i];
					diffNum += 1;
				}
			}
			return diffNum;
		}
    }
};