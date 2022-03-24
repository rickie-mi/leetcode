#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
const int N = 510;
char a[N][N];
int pre[N][N];
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	while (q--)
	{
		int x1, x2, y1, y2;
		//scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		cin >> x1 >> y1 >> x2 >> y2;
		pre[x1][y1]++;
		pre[x1][y2 + 1]--;
		pre[x2 + 1][y1]--;
		pre[x2 + 1][y2 + 1]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			pre[i][j] = pre[i][j] - pre[i - 1][j - 1] + pre[i][j - 1] + pre[i - 1][j];
			//cout << pre[i][j];
			if (pre[i][j] % 2 == 0) cout << a[i][j];
			else
			{
				if (a[i][j] >= 'A' && a[i][j] <= 'Z') cout << (char)((a[i][j] - 'A') + 'a');
				else cout<< (char)((a[i][j] - 'a') + 'A');
			}
		}
		cout << endl;
	}
	return 0;
}