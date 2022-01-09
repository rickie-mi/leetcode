#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> ans(n, vector<int>(n));
	int l = 0, r = n - 1, h = 0, b = n - 1;
	int cnt = 1;
	while (cnt <= n*n)
	{
		if (h <= b)
		{
			for (int i = l; i <= r; i++)
			{
				ans[h][i] = cnt++;
			}
			h++;
		}
		if (l <= r)
		{
			for (int i = h; i <= b; i++)
			{
				ans[i][r] = cnt++;
			}
			r--;
		}
		if (h <= b)
		{
			for (int i = r; i >= l; i--)
			{
				ans[b][i] = cnt++;
			}
			b--;
		}
		if (l <= r)
		{
			for (int i = b; i >= h; i--)
			{
				ans[i][l] = cnt++;
			}
			l++;
		}
	}
	return ans;
}