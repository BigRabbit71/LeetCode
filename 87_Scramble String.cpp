class Solution {
public:
    bool isScramble(string s1, string s2) {
        // case 1
        if(s1.size() != s2.size()) return false;
        
        // case 2
        if(s1.empty() && s2.empty()) return true;
        
        // case 3
        int n = s1.size();
        vector<vector<vector<bool>>> f(n, vector<vector<bool>>(n, vector<bool>(n+1, false)));
        
        // init: len=1
        // f[i][j][k]: s1 start from s[i], s2 start from s[j], substring length=k,
        // s1 substring can transform to s2 substring 
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(s1[i] == s2[j])
                    f[i][j][1] = true;
            }
        }
        
        //len>1
        for(int len=2; len<=n; ++len){
            for(int i=0; i<=(n-len); ++i){// s1 start from s[i]
                for(int j=0; j<=(n-len); ++j){// s2 start from s[j]
                    for(int k=1; k<=(len-1); ++k){ // left substring's len
                        // s1 left-> s2 left, s1 right-> s2 right
                        if(f[i][j][k] && f[i+k][j+k][len-k]){
                            f[i][j][len] = true;
                            break;
                        }
                        
                        // s1 left-> s2 right, s1 right-> s2 left
                        if(f[i][j+len-k][k] && f[i+k][j][len-k]){
                            f[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return f[0][0][n];
    }
};