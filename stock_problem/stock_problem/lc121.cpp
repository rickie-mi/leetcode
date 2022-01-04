#include <iostream>
#include <vector>
using namespace std;

//ֻ���Խ���һ�Σ�����k����Ϊ1������Ҫ����
int maxProfit(vector<int>& prices) {
    //dp[i][1][1] = max(dp[i-1][1][1], - prices[i]);
    //dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]);
    //����kֻ����Ϊ1

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

