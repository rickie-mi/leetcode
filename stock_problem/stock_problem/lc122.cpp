#include <iostream>
#include <vector>
using namespace std;


//可以无限次交易，所以k和k-1是一个概念
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp0 = 0;
    int dp1 = -prices[0];
    for (int i = 1; i < n; i++)
    {
        dp0 = max(dp0, dp1 + prices[i]);
        dp1 = max(dp1, dp0 - prices[i]);
    }
    return dp0;
}