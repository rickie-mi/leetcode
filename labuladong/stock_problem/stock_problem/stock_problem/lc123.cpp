#include <iostream>
#include <vector>
using namespace std;
//最多完成两笔交易，所以k==2,要做四次
int maxProfit(vector<int>& prices) {
    //有两笔交易，所以k为2
    int n = prices.size();
    //vector<vector<vector<int>>> dp(n,vector<vector<int>>(3, vector<int>(2)));
    int dpi10 = 0, dpi11 = -prices[0], dpi20 = 0, dpi21 = -prices[0];
    for (int i = 0; i < n; i++)
    {
        int temp = dpi10;
        dpi10 = max(dpi10, dpi11 + prices[i]);
        dpi11 = max(dpi11, -prices[i]);
        dpi20 = max(dpi20, dpi21 + prices[i]);
        dpi21 = max(dpi21, temp - prices[i]);
    }
    return dpi20;
}