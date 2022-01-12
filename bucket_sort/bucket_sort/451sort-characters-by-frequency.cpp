#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<char, int> PII;

//桶排序
string frequencySort1(string s) {
	string ans = "";
	unordered_map<char, int> mp;
	int maxfreq = -1;
	for (auto &c : s)
	{
		mp[c]++;
		maxfreq = max(maxfreq, mp[c]);
	}
	vector<string> bucket(maxfreq + 1);
	for (auto [key, value] : mp)
	{
		bucket[value].push_back(key);
	}
	for (int i = maxfreq; i>0; i--)
	{
		string temp = bucket[i];
		for (int j = 0; j<temp.size(); j++)
			ans += string(i, temp[j]);
	}
	return ans;
}

//哈希表+优先队列
static bool cmp(PII &x, PII &y)
{
	return x.second < y.second;
}
string frequencySort2(string s) {
	unordered_map<char, int> mp;
	for (auto & c : s)
		mp[c]++;
	priority_queue<PII, vector<PII>, decltype(&cmp)> pq(cmp);
	for (auto &[key, value] : mp)
		pq.push({ key, value });
	string ss = "";
	while (pq.size())
	{
		string temp = string(pq.top().second, pq.top().first);
		pq.pop();
		ss += temp;
	}
	return ss;
}
