#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	int l = 0, r = nums.size() - 1;
	if (r<l) return vector<int>{-1, -1};
	while (l<r)
	{
		int mid = (l + r) >> 1;
		if (nums[mid] >= target)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	if (nums[l] != target) return vector<int>{-1, -1};
	vector<int> ans;
	ans.push_back(l);
	r = nums.size() - 1;
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
	ans.push_back(l);
	return ans;
}