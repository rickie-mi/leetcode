class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto & a, auto & b)
        {
            if(a[0] != b[0]) return a[0] < b[0];
            else return a[1] > b[1];
        });
        //计算dp;
        int n = envelopes.size();
        vector<int> dp(n, 1);
        int res = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};