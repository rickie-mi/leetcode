#include <iostream>
#include <vector>
using namespace std;

//�������ѣ����൱������ʱ�۸����
int maxProfit(vector<int>& prices, int fee) {
    //�����Ʊ��ʱ��������Ѹ�����
    int n = prices.size();
    int dp0 = 0, dp1 = -prices[0] - fee;
    for (int i = 1; i < n; i++)
    {
        int temp = dp1;
        dp1 = max(dp1, dp0 - prices[i] - fee);
        dp0 = max(dp0, temp + prices[i]);
    }
    return dp0;
}