class Solution {
public:
    int minDistance(string word1, string word2) {
        // case 1
        if(word1.empty() && word2.empty()) return 0;
        
        // case 2
        if(word1.empty() && !word2.empty()) return word2.size();
        
        // case 3
        if(!word1.empty() && word2.empty()) return word1.size();
        
        // normal case
        int m = word1.size(), n = word2.size();
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));
        // init
        for(int i=0; i<=m; ++i) f[i][0] = i;
        for(int j=0; j<=n; ++j) f[0][j] = j;
        
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                // insert, delete, replace, same
                if(word1[i-1] == word2[j-1])
                    f[i][j] = min(min(min(f[i][j-1]+1, f[i-1][j]+1), f[i-1][j-1]+1), f[i-1][j-1]);
                else
                    f[i][j] = min(min(f[i][j-1]+1, f[i-1][j]+1), f[i-1][j-1]+1);
            }
        }
        
        return f[m][n];
    }
};