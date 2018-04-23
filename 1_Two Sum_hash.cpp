class Solution {
public:
    /*
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        map<int, int> mymap;
        vector<int> res;
         
        for(int i=0; i<numbers.size(); ++i){
            if(mymap.find(numbers[i]) != mymap.end()){
                res.push_back(mymap[numbers[i]]);
                res.push_back(i);
            }else{
                mymap.insert(make_pair(target-numbers[i], i));
            }
        }
        
        return res;
    }
};