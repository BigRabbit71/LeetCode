class Solution {
public:
    int numDecodings(string s) {
        // empty string
        if(s.empty()) return 0;
        
        // string is not empty
        int n = s.size();
        vector<int> f(n+1, 0);
        // Init
        f[0] = 1;
        
        // n = 1
        if(n==1){
            if((s[0]-'0')>=1 && (s[0]-'0')<=26) f[1] = 1;
            return f[1];
        }
        
        // n >= 2  
        for(int i=1; i<=n; ++i){
            if(i==1){
                if(s[i-1]-'0'>=1 && s[i-1]-'0'<=9) 
                    f[i] = 1;
            }else{
                if(s[i-1]-'0'>=1 && s[i-1]-'0'<=9)
                    f[i] += f[i-1];
                if((s[i-2]-'0')*10+s[i-1]-'0' >= 10 && (s[i-2]-'0')*10+s[i-1]-'0' <= 26)
                    f[i] += f[i-2];
            }  
        }
        
        return f[n];
    }
};