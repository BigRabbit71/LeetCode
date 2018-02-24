class Solution {
public:
    bool isMatch(string s, string p) {
        // case 1
        if(s.empty() && p.empty()) return true;
        
        // case 2
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m+1, vector<bool>(n+1, false));
        // init
        f[0][0] = true;
        for(int i=1; i<=m; ++i) f[i][0] = false;
        
        for(int i=0; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if((p[j-1]=='?' || p[j-1]==s[i-1]) && i>=1)
                    f[i][j] = f[i][j] || f[i-1][j-1];
                
                if(p[j-1]=='*'){
                    if(i==0)
                        f[i][j] = f[i][j] || f[i][j-1];
                    if(i>=1)
                        f[i][j] = f[i][j] || f[i][j-1] || f[i-1][j];      
                }
            }
        }
        
        return f[m][n];
    }
};