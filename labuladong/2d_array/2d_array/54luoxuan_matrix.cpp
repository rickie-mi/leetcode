#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	int l = 0, r = n - 1, h = 0, b = m - 1;
	vector<int> ans;
	int cnt = 0;
	while (cnt<m*n)
	{
		if (h <= b)
		{
			for (int i = l; i <= r; i++)
			{
				ans.push_back(matrix[h][i]);
				cnt++;
			}
			h++;
		}
		if (l <= r)
		{
			for (int i = h; i <= b; i++)
			{
				ans.push_back(matrix[i][r]);
				cnt++;
			}
			r--;
		}
		if (h <= b)
		{
			for (int i = r; i >= l; i--)
			{
				ans.push_back(matrix[b][i]);
				cnt++;
			}
			b--;
		}
		if (l <= r)
		{
			for (int i = b; i >= h; i--)
			{
				ans.push_back(matrix[i][l]);
				cnt++;
			}
			l++;
		}
	}
	return ans;
}