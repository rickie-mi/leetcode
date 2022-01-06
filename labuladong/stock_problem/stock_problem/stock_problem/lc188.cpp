#include <iostream>
#include <vector>
using namespace std;
//����k��Ҫ�ж�k�Ĵ�С�������ڴ�ᳬ
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0 || k == 0) return 0;
    if (k <= n / 2)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2)));
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i == 0)
                {
                    dp[0][j][0] = 0;
                    dp[0][j][1] = -prices[i];
                }
                else
                {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }
        return dp[n - 1][k][0];
    }
    else
    {
        //k̫�󣬿��Կ��������޴ε��������ʱk����ֵ�Ѿ�û��Ӱ��
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < n; i++)
        {
            int temp = dp0;
            dp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, temp - prices[i]);
        }
        return dp0;
    }

}
};