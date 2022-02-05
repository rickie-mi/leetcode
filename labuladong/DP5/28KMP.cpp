class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int m = needle.size(), n = haystack.size();
        vector<vector<int>> dp(m, vector<int>(256));
        KMP(needle, dp);
        int j=0;
        for(int i=0; i<n; i++)
        {
            j = dp[j][haystack[i]];
            if(j == m) return i-m+1;
        }
        return -1;
    }

    void KMP(string needle, vector<vector<int>> &dp)
    {
        int X = 0;
        dp[0][needle[0]] = 1;
        for(int i=1; i<needle.size(); i++)
        {
            for(int j=0; j<256; j++)
                dp[i][j] = dp[X][j];
            dp[i][needle[i]] = i+1;
            X = dp[X][needle[i]];
        }
    }
};