#include <iostream>
#include <vector>
using namespace std;

//只可以交易一次，所以k这里为1，不需要遍历
int maxProfit(vector<int>& prices) {
    //dp[i][1][1] = max(dp[i-1][1][1], - prices[i]);
    //dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]);
    //这里k只可以为1

    int n = prices.size();
    int dp0 = 0;
    int dp1 = -prices[0];
    for (int i = 1; i < n; i++)
    {
        dp0 = max(dp0, dp1 + prices[i]);
        dp1 = max(dp1, -prices[i]);
    }
    return dp0;
}

