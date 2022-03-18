#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
typedef pair<int, int> PII;


void chess(unordered_set<PII>& history, vector<vector<char>>& mp, int x, int y, int t) {
	int n = mp.size();
	for (int i = n - 1; i > x; i--)
	{
		if(mp[i])
	}
}

int main() {
	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		vector<vector<char>> mp(n, vector<char>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> mp[i][j];
			}
		}
		unordered_set<PII> history;
		for (int i = 0; i < m; i++)
		{
			history.clear();
			int x, y;
			cin >> x >> y;
			chess(history, mp, x, y, i);
		}
	}
}