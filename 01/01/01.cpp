// 01.cpp : 定义控制台应用程序的入口点。
/*
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include "stdafx.h"
#include <stdlib.h> 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//using std::vector

class solution {
public:
    vector<int> twosum(vector<int>& nums, int target) {
		vector<int> result;
		////升序排
		//sort(nums.begin(), nums.end(), greater<int>());

		//对nums中的每一个元素
		for(int i=0; i<nums.size()-1; i++){
			for(int j=i+1; j<nums.size(); j++){
				if( (nums[i] + nums[j]) == target ){
					result.push_back(i);
					result.push_back(j);
					break;
				}
			}
		}

		return result;
    }


};

int _tmain()
{
	vector<int> nums;
	vector<int> result;
	cout<<"Input: "<<endl;
	int num;
	while(cin>>num){
		nums.push_back(num);
	}

	solution mysolution;
	result = mysolution.twosum(nums, 9);
	cout<<result[0]<<" "<<result[1]<<endl;

	return 0;
}

