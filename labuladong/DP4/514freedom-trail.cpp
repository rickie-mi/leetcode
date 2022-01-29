class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<vector<int>> dp(m,vector<int>(n, INT_MAX));
        unordered_map<char, vector<int>> mp;
        for(int i=0; i<n; i++)
        {
            mp[ring[i]].push_back(i);
        }
        for(auto idx : mp[key[0]])
        {
            dp[0][idx] = 1 + min(idx, n-idx);
        }
        for(int i=1; i<m; i++)
        {
            char key0 = key[i];
            for(int j: mp[key0])
            {
                    for(int k=0; k<n; k++)
                    {
                        if(dp[i-1][k] == INT_MAX)
                            continue;
                        dp[i][j] = min(dp[i][j], dp[i-1][k] +1+min(abs(k-j), n-abs(k-j)));
                    }
           
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        {
            ans = min(ans, dp[m-1][i]);
        }
        return ans;
    }
};