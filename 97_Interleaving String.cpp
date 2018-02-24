class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // case 1
        if(s1.size()+s2.size() != s3.size()) return false;
        
        // case 2
        if(s1.empty() && !s2.empty()) return s2==s3;
        
        // case 3
        if(s2.empty() && !s1.empty()) return s1==s3;
        
        // case 4
        if(s1.empty() && s2.empty() && s3.empty()) return true;
        
        // case normal:
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> f(n+1, vector<bool>(m+1, false));
        // init
        f[0][0] = true;
        for(int j=1; j<=m; ++j){
            if(s3[0+j-1] == s2[j-1])
                f[0][j] = f[0][j-1];
        }
        for(int i=1; i<=n; ++i){
            if(s3[0+i-1] == s1[i-1])
                f[i][0] = f[i-1][0];
        }
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s3[i+j-1] == s1[i-1] && s3[i+j-1] != s2[j-1])
                    f[i][j] = f[i-1][j];
                if(s3[i+j-1] == s2[j-1] && s3[i+j-1] != s1[i-1])
                    f[i][j] = f[i][j-1];
                if(s3[i+j-1] == s1[i-1] && s3[i+j-1] == s2[j-1])
                    f[i][j] = (f[i-1][j] || f[i][j-1]);
            }
        }
        
        return f[n][m];
    }
};