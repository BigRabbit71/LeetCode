class Solution {
public:
    int minCut(string s) {
        if(s.empty()) return 0;
        
        int n = s.size();
        
        // generate palindrome judge vector
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for(int mid=0; mid<n; ++mid){
            //odd， mid is the mid
            int l, r;
            l = r = mid;
            while(l>=0 && r<n && s[l]==s[r]){
                isPalin[l][r] = true;
                --l;
                ++r;
            }
    
            //even, gap is the mid
            l = mid;
            r = mid+1;
            while(l>=0 && r<n && s[l]==s[r]){
                isPalin[l][r] = true;
                --l;
                ++r;
            }
        }
        
        //count the number of palindrome
        vector<int> f(n+1, 0);
        for(int i=1; i<=n; ++i){
            f[i] = INT_MAX;
            for(int j=0; j<i; ++j){
                if(isPalin[j][i-1])
                    f[i] = min(f[i], f[j]+1);
            }
        }
        
        return f[n]-1;
    }
};