class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> f(2, vector<int>(n, 0));
        // index for rolling array
        int now=0, old=1;
        for(int i=0; i<m; ++i){
            // rolling array
            old = now;
            now = 1-old;
            
            for(int j=0; j<n; ++j){
                if(i==0 && j==0) f[now][j] = grid[0][0];// Important! f[now][j] not f[0][0]
                if(i==0 && j>0) f[now][j] = f[now][j-1] + grid[i][j];
                if(i>0 && j==0) f[now][j] = f[old][j] + grid[i][j];
                if(i>0 && j>0){
                    f[now][j] = min(f[old][j], f[now][j-1]) + grid[i][j];
                } 
            }
        }
        
        return f[now][n-1];
    }
};