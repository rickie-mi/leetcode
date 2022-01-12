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
			mp[black] = -1;   //ֻ��Ϊ�˼�¼��������Щ����blacklist�еģ����ں�����O(1)ʱ���ҵ�
		int last = n - 1;
		for (int black : blacklist)
		{
			if (black >= sz)  //������ں���Ͳ�����
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
