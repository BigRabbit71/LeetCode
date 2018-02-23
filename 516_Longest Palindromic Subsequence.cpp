class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // case 1: s len=0
        if(s.empty()) return 0;
        
        // case 2: s len>0
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));    //0 means none
        
        // init: len=1
        for(int i=0; i<n; ++i) f[i][i] = 1;
        
        for(int len=2; len<=n; ++len){    //length
            for(int l=0; l<=(n-1-len+1); ++l){
                int r = l+len-1;
                if(s[l]!=s[r]){
                    f[l][r] = max(f[l+1][r], f[l][r-1]);
                }else{
                    f[l][r] = max(max(f[l+1][r], f[l][r-1]), f[l+1][r-1]+2);
                }
            }
        }
        
        return f[0][n-1];
        
    }
};