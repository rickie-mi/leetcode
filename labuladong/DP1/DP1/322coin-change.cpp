#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
	if (amount == 0) return 0;
	int n = coins.size();
	sort(coins.begin(), coins.end());
	if (amount < coins[0]) return -1;
	vector<int> dp(amount + 1, -1);
	dp[0] = 0;
	dp[coins[0]] = 1;
	for (int i = coins[0] + 1; i <= amount; i++)
	{
		int ans = INT_MAX;
		for (int j = 0; j<n; j++)
		{
			int c = coins[j];
			if (i - c < 0 || dp[i - c] == -1)
				continue;
			ans = min(ans, dp[i - c] + 1);
		}
		if (ans != INT_MAX)
			dp[i] = ans;
	}
	return dp[amount];
}