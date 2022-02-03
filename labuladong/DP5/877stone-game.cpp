//法一
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        //base case
        for(int i=0; i<n; i++)
            dp[i][i] = piles[i];
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                dp[i][j] = max(piles[i]-dp[i+1][j], piles[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};


//法一优化
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n,0);
        //base case
        for(int i=0; i<n; i++)
            dp[i] = piles[i];
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                dp[j] = max(piles[i]-dp[j], piles[j]-dp[j-1]);
            }
        }
        return dp[n-1] > 0;
    }
};



//法二
typedef pair<int,int> PII;
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<PII>> dp(n, vector<PII>(n,{0,0}));
        //base case
        for(int i=0; i<n; i++)
            dp[i][i] = {piles[i], 0};
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                int ll = dp[i+1][j].second;
                int rr = dp[i][j-1].second;
                if(ll + piles[i] > rr + piles[j])
                {
                    dp[i][j].first = ll+piles[i];
                    dp[i][j].second = dp[i+1][j].first;
                }
                else
                {
                    dp[i][j].first = rr+piles[j];
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }
        return dp[0][n-1].first > dp[0][n-1].second;
    }
};
