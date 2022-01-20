#include <iostream>
#include <vector>
using namespace std; 

class Solution {
private:
	vector<int> order;
	vector<vector<int>> info;
	vector<bool> visited;
	vector<bool> onpath;
	bool hascycle;
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		info.resize(numCourses);
		visited.resize(numCourses);
		onpath.resize(numCourses);
		for (auto & pre : prerequisites)
			info[pre[1]].push_back(pre[0]);
		for (int i = 0; i<numCourses && !hascycle; i++)
			check(i);
		if (hascycle) return vector<int>{};
		else
		{
			reverse(order.begin(), order.end());
			return order;
		}
	}

	void check(int st)
	{
		if (onpath[st])
		{
			hascycle = true;
			return;
		}
		if (hascycle || visited[st])
			return;
		visited[st] = true;
		onpath[st] = true;
		for (int i = 0; i<info[st].size() && !hascycle; i++)
			check(info[st][i]);
		order.push_back(st);
		onpath[st] = false;
	}
};