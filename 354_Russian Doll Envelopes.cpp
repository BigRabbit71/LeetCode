class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty()) return 0;
        
        // default sorted by first one
        sort(envelopes.begin(), envelopes.end());
        
        int n = envelopes.size();
        vector<int> f(n, 1);
        for(int j=1; j<n; ++j){
            for(int i=0; i<j; ++i){
                if(envelopes[i].first < envelopes[j].first && envelopes[i].second < envelopes[j].second && f[i]+1 >f[j])
                    f[j] = f[i]+1;
            }
        }
        
        int res = INT_MIN;
        for(int i=0; i<n; ++i){
            res = max(res, f[i]);
        }
        
        return res;
    }
};