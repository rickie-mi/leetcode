#include <vector>
#include <queue>
using namespace std;
class Solution{
private:
	vector<int> color;
	bool flag;
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		color.resize(n);
		flag = true;
		for (int i = 0; i<n && flag; i++)
		{
			if (color[i] == 0)
				bfs(graph, i, 1);
		}
		return flag;
	}
	void bfs(vector<vector<int>>& graph, int node, int c)
	{
		color[node] = c;
		queue<int> q;
		q.push(node);
		while (q.size() && flag)
		{
			int t = q.front();
			//cout<<t;
			q.pop();
			for (auto tt : graph[t])
			{
				if (color[tt] != 0)
				{
					if (color[tt] == color[t])
					{
						flag = false;
						return;
					}
				}
				else
				{
					color[tt] = 3 - color[t];
					q.push(tt);
					//cout<<tt<<endl;
				}
			}
		}
	}
};