#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
typedef pair<int, int> PII;
int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
	vector<vector<int>> cnt(m, vector<int>(n, 0));
	int st1, st2, ed1, ed2;
	cin >> st1 >> st2 >> ed1 >> ed2;
	dist[st1][st2] = 0; cnt[st1][st2] = 1;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		cnt[temp1][temp2] = -1;
	}
	queue<PII> q;
	q.push({ st1,st2 });
	while (q.size())
	{
		auto c = q.front();
		q.pop();
		int temp1 = c.first, temp2 = c.second;
		int distance = dist[temp1][temp2];
		if (temp1 + 1 < m && cnt[temp1+1][temp2]!=-1)
		{
			if (distance + 1 <= dist[temp1 + 1][temp2])
			{
				if (distance + 1 == dist[temp1 + 1][temp2])
					cnt[temp1 + 1][temp2]++;
				else{
					dist[temp1 + 1][temp2] = distance + 1;
					cnt[temp1 + 1][temp2] = 1;
				}
				q.push({ temp1 + 1,temp2 });
			}
		}
		if (temp1 - 1 >=0 && cnt[temp1 - 1][temp2] != -1)
		{
			if (distance + 1 <= dist[temp1 - 1][temp2])
			{
				if (distance + 1 == dist[temp1 - 1][temp2])
					cnt[temp1 - 1][temp2]++;
				else
				{
					dist[temp1 - 1][temp2] = distance + 1;
					cnt[temp1 - 1][temp2] = 1;
				}
				q.push({ temp1 - 1,temp2 });
			}
		}
		if (temp2 + 1 < n && cnt[temp1][temp2 + 1] != -1)
		{
			if (distance + 1 <= dist[temp1][temp2 + 1])
			{
				if (distance + 1 == dist[temp1][temp2 + 1])
					cnt[temp1][temp2 + 1]++;
				else{
					dist[temp1][temp2 + 1] = distance + 1;
					cnt[temp1][temp2 + 1] = 1;
				}
				q.push({ temp1,temp2 + 1 });
			}
		}
		if (temp2 - 1 >= 0 && cnt[temp1][temp2 - 1] != -1)
		{
			if (distance + 1 <= dist[temp1][temp2 - 1])
			{
				if (distance + 1 == dist[temp1][temp2 - 1])
					cnt[temp1][temp2 - 1]++;
				else{
					dist[temp1][temp2 - 1] = distance + 1;
					cnt[temp1][temp2 - 1] = 1;
				}
				q.push({ temp1,temp2 - 1 });
			}
		}
	}
	cout << cnt[ed1][ed2] << ' ' << dist[ed1][ed2];
	return 0;

}
