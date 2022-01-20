#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
	vector<vector<string>> ans;
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> temp(n, string(n, '.'));
		vector<bool> col(n, false);
		vector<bool> dig(2 * n, false);
		vector<bool> rdig(2 * n, false);
		dfs(temp, col, dig, rdig, 0, n);
		return ans;
	}

	void dfs(vector<string> &temp, vector<bool> &col, vector<bool> &dig, vector<bool> &rdig, int line, int n)
	{
		if (line == n)
		{
			ans.push_back(temp);
			return;
		}
		for (int i = 0; i<n; i++)
		{
			if (col[i] == false && dig[i - line + n] == false && rdig[i + line] == false)
			{
				col[i] = true; dig[i - line + n] = true; rdig[i + line] = true;
				temp[line][i] = 'Q';
				dfs(temp, col, dig, rdig, line + 1, n);
				col[i] = false; dig[i - line + n] = false; rdig[i + line] = false;
				temp[line][i] = '.';
			}
		}
	}
};