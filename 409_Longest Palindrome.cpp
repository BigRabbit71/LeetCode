class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> char_map(128, 0);
        for(auto c:s){
            char_map[c]++;
        }
        
        int max_length=0, mid_flag=0;
        for(int i=0; i<128; ++i){
            if(char_map[i]%2 == 0) max_length += char_map[i];
            else{
                max_length += char_map[i]-1;
                mid_flag = 1;
            }
        }
        
        return (max_length+mid_flag);
    }
};