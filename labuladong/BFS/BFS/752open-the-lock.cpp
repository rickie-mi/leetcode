#include<queue>
#include<vector>
#include<string>
using namespace std; 
#include <unordered_set>
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		string start = "0000";
		unordered_set<string> st;
		for (auto dead : deadends) st.insert(dead);
		if (st.count(start)) return -1;
		int cnt = 0;
		queue<string> q;
		q.push(start);
		while (q.size())
		{
			int sz = q.size();
			while (sz--)
			{
				string temp = q.front();
				q.pop();
				if (temp == target) return cnt;
				for (int i = 0; i<4; i++)
				{
					string pp = temp;
					pp[i] = (pp[i] - '0' + 1) % 10 + '0';
					if (st.count(pp) == 0)
					{
						q.push(pp);
						st.insert(pp);
					}
					pp = temp;
					pp[i] = (pp[i] - '0' + 9) % 10 + '0';
					if (st.count(pp) == 0)
					{
						q.push(pp);
						st.insert(pp);
					}
				}
			}
			cnt++;
		}
		return -1;
	}
};