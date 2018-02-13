class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int> > f(m, vector<int>(n, 0));
        //// Init
        //f[0][0] = 1;
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(obstacleGrid[i][j] == 1){
                    f[i][j] = 0;
                }
                else{
                    if(i==0 && j==0) f[i][j] = 1;   // init
                    else if(i==0 && j>0) f[i][j] = f[i][j-1];
                    else if(i>0 && j==0) f[i][j] = f[i-1][j];
                    else 
                        f[i][j] = f[i-1][j] + f[i][j-1];       
                }   
            }
        }

        return f[m-1][n-1];
    }
};