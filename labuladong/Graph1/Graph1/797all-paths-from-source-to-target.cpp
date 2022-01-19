#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> totalans;
	int n;
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<int> temp{ 0 };
		n = graph.size();
		findRoute(temp, graph, 0);
		return totalans;
	}

	void findRoute(vector<int>& temp, vector<vector<int>>& graph, int st)
	{
		if (st == n - 1)
		{
			totalans.push_back(temp);
			return;
		}
		for (int i = 0; i<graph[st].size(); i++)
		{
			temp.push_back(graph[st][i]);
			findRoute(temp, graph, graph[st][i]);
			temp.pop_back();
		}
	}
};