class Solution {
public:
    /**
     * @param s: input string, e.g."abcdzdcab"
     * @return: the longest palindromic substring, e.g."cdzdc"
     */
    string longestPalindrome(string &s) {
        // write your code here
        string res;
        // case err:
        if(s.empty())
            return res;
        
        // case normal:
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        // init: 
        int longestLen = 1, start = 0;
        // len = 1
        for(int i=0; i<s.size(); ++i){
            isPalindrome[i][i] = true;
        }
        // len = 2
        for(int i=0; i<s.size()-1; ++i){
            if(s[i]==s[i+1]){
                isPalindrome[i][i+1] = true;
                longestLen = 2;
                start = i;
            }
        }
        // len = 3
        for(int len=3; len<=s.size(); ++len){
            for(int i=0; i+len-1<s.size(); ++i){
                // 这里可以在循环内部初始化j，可以在for循环的时候少一个变量
                int j=i+len-1; 
                if(s[i] == s[j] && isPalindrome[i+1][j-1]){
                    isPalindrome[i][j] = true;
                    longestLen = len;
                    start = i;
                }
            }
        }

        res = s.substr(start, longestLen);
        return res;
    }
};