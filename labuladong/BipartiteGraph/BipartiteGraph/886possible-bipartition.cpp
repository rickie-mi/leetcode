#include <vector>
#include <queue>
using namespace std; 

class Solution {
private:
	bool flag;
	vector<int> color;
	vector<vector<int>> info;
public:
	bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		flag = true;
		color.resize(n + 1);
		info.resize(n + 1);
		for (auto & dis : dislikes)
		{
			info[dis[0]].push_back(dis[1]);
			info[dis[1]].push_back(dis[0]);
		}
		for (int i = 1; i <= n && flag; i++)
		{
			if (color[i] == 0)
				dfs(i, 1);
		}
		return flag;
	}

	void dfs(int node, int c)
	{
		color[node] = c;
		for (int i = 0; i<info[node].size() && flag; i++)
		{
			int tt = info[node][i];
			//cout<<tt;
			if (color[tt] == 0)
			{
				dfs(tt, 3 - c);
			}
			else
			{
				if (color[tt] == c)
				{
					flag = false;
					return;
				}
			}
		}
	}
};