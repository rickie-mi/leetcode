#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
	unordered_map<int, int> mp;
	int sz;
public:
	Solution(int n, vector<int>& blacklist) {
		sz = n - blacklist.size();
		for (int black : blacklist)
			mp[black] = -1;   //只是为了记录下来有哪些是在blacklist中的，便于后面在O(1)时间找到
		int last = n - 1;
		for (int black : blacklist)
		{
			if (black >= sz)  //本身就在后面就不管了
				continue;
			while (mp.count(last))
				last--;
			mp[black] = last--;
		}
	}

	int pick() {
		int idx = rand() % sz;
		if (mp.count(idx))
			return mp[idx];
		else
			return idx;
	}
};
