class Solution {
public:
    /**
     * @param s: input string, e.g."abcdzdcab"
     * @return: the longest palindromic substring, e.g."cdzdc"
     */
    string longestPalindrome(string s) {
        // write your code here
        string res;
        // case err:
        if(s.empty())
            return res;
        
        // case normal:
        int longestLen = 1, strStart = 0;
        for(int i=0; i<s.size(); ++i){
            int len1=1, len2=1;
            
            len1 = getLongestLengthOfPalidrome(s, i, i);
                            
            if(i+1<s.size()){
                len2 = getLongestLengthOfPalidrome(s, i, i+1);
            }
                
            if(len1 > longestLen || len2 > longestLen){
                longestLen = max(len1, len2);
                if(longestLen%2 == 1){
                    strStart = i - longestLen/2;
                }else{
                    strStart = i - (longestLen/2 - 1);
                }
            }
        }

        res = s.substr(strStart, longestLen);
        return res;
    }
    
private:
    int getLongestLengthOfPalidrome(string s, int mid_left, int mid_right){
        int longestLen;
        
        // init:
        if(mid_left == mid_right){
            longestLen = 1;
            --mid_left;
            ++mid_right;
        }else{
            longestLen = 0;
        }
            
        while(mid_left>=0 && mid_right<=s.size()-1 && s[mid_left]==s[mid_right]){
            longestLen += 2;
            --mid_left;
            ++mid_right;
        }
        
        return longestLen;
    }
};