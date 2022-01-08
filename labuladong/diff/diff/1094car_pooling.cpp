#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> diff;
int n;
void incre(int i, int j, int c)
{
	diff[i] += c;
	if (j < diff.size()) diff[j] -= c;
}

bool carPooling(vector<vector<int>>& trips, int capacity) {
	diff.resize(1010);
	n = 0;
	for (auto trip : trips)
	{
		incre(trip[1], trip[2], trip[0]);
		n = max(n, trip[2]);
	}
	if (diff[0] > capacity) return false;
	cout << diff[0];
	for (int i = 1; i<n; i++)
	{
		diff[i] += diff[i - 1];
		cout << diff[i];
		if (diff[i] > capacity) return false;
	}
	return true;
}