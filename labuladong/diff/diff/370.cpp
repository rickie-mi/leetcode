#include <iostream>
#include <vector>
using namespace std;

void incre(int i, int j, int c, vector<int> &diff)
{
	diff[i] += c;
	if (j + 1 < diff.size()) diff[j + 1] -= c;
}

vector<int> getModifiedArray(int length, vector<vector<int>> updates) {
	vector<int> diff(length, 0);
	for (auto update : updates)
	{
		incre(update[0], update[1], update[2], diff);
	}
	vector<int> res(length);
	res[0] = diff[0];
	for (int i = 1; i < length; i++)
		res[i] = res[i - 1] + diff[i];
	return res;
}

int main()
{
	int n = 5;
	vector<vector<int>> updates;
	updates.push_back({ 1, 3, 2 });
	updates.push_back({ 2, 4, 3 });
	updates.push_back({ 0, 2, -2 });
	auto res = getModifiedArray(n, updates);
	return 0;
}
