#include <iostream>
#include <vector>
using namespace std;
//包含冷冻期，所交易之后一天不能交易
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //vector<vector<int>> dp(n,vector<int>(2));
    int dp0 = 0;
    int dp1 = -prices[0];
    int dp2 = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = dp0;
        dp0 = max(dp0, dp1 + prices[i]);
        if (i - 2 >= 0)
            dp1 = max(dp1, dp2 - prices[i]);
        else
            dp1 = max(dp1, dp0 - prices[i]);
        dp2 = temp;
    }
    return dp0;
}