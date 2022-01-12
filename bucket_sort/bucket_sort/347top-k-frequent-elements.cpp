#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<char, int> PII; 
//桶排序
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> mp;
	int maxfreq = -1;
	for (auto num : nums)
	{
		mp[num]++;
		maxfreq = max(maxfreq, mp[num]);
	}
	vector<vector<int>> bucket(maxfreq + 1, vector<int>());
	for (auto &[key, value] : mp)
	{
		bucket[value].push_back(key);
	}
	vector<int> ans;
	for (int i = maxfreq; i>0 && ans.size()<k; i--)
	{
		if (bucket[i].size() == 0)
			continue;
		for (int j = 0; j<bucket[i].size(); j++)
			ans.push_back(bucket[i][j]);
	}
	return ans;
}

//哈希表+优先队列
static bool cmp(PII x, PII y)
{
	return x.second > y.second;
}
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> mp;
	for (int num : nums) mp[num]++;
	priority_queue<PII, vector<PII>, decltype(&cmp)> pq(cmp);
	for (auto[key, value] : mp)
	{
		if (pq.size() < k)
			pq.push({ key, value });
		else
		{
			if (value > pq.top().second)
			{
				pq.pop();
				pq.push({ key, value });
			}
		}
	}
	vector<int> ans;
	while (pq.size())
	{
		ans.push_back(pq.top().first);
		pq.pop();
	}
	return ans;
}