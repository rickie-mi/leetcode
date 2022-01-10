#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
	int l = 0, r = nums.size() - 1;
	while (l<r)
	{
		int mid = (l + r + 1) >> 1;
		if (nums[mid] <= target)
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	if (nums[l] != target)
		return -1;
	else
		return l;

}