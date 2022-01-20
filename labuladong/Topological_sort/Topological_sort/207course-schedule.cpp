#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
	bool hascycle;
	vector<bool> visited;
	vector<bool> onpath;
	vector<vector<int>> info;
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		visited.resize(numCourses);
		onpath.resize(numCourses);
		info.resize(numCourses);
		for (auto &pre : prerequisites)
		{
			info[pre[1]].push_back(pre[0]);
		}
		for (int i = 0; i<numCourses && !hascycle; i++)
			check(i);
		return !hascycle;
	}
	void check(int st)
	{
		if (onpath[st])
		{
			hascycle = true;
			return;
		}
		if (visited[st] || hascycle) return;
		visited[st] = true;
		onpath[st] = true;
		for (auto i : info[st])
			check(i);
		onpath[st] = false;
	}
};