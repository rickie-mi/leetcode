class Solution {
public:
    int numSquares(int n) {
        if(n<4) return n;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 3;
        for(int i= 4; i<=n; i++){
            int c = sqrt(i);
            for(int j=1; j<=c; j++)
            {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};