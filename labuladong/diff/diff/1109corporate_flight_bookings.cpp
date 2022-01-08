#include <iostream>
#include <vector>
using namespace std;

vector<int> diff;
void incre(int i, int j, int c)
{
	diff[i] += c;
	if (j + 1<diff.size()) diff[j + 1] -= c;
}

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
	diff.resize(n);
	for (auto booking : bookings)
	{
		incre(booking[0] - 1, booking[1] - 1, booking[2]);
	}
	vector<int> ans(n);
	ans[0] = diff[0];
	for (int i = 1; i<n; i++)
		ans[i] = ans[i - 1] + diff[i];
	return ans;
}
