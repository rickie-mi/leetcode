#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS_1(vector<int>& nums) {
	int n = nums.size();
	//最大是长度为n的堆
	vector<int> heap(n, 0);
	int heapnum = 0;
	for (int i = 0; i<n; i++)
	{
		int temp = nums[i];
		//找到大于等于temp的最大数字
		int ll = 0, rr = heapnum;
		while (ll<rr)
		{
			int mid = (ll + rr) >> 1;
			if (heap[mid] >= temp)  rr = mid;
			else ll = mid + 1;
		}
		//cout<<ll<<' '<<rr<<endl;
		if (ll == heapnum)  heap[heapnum++] = temp;
		heap[ll] = temp;
	}
	return heapnum;
}

int lengthOfLIS_2(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n, 1);  //base case
	int res = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<i; j++)
		{
			if (nums[j] < nums[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		//更新最终结果
		res = max(dp[i], res);
	}
	return res;
}

int main()
{
	vector<int> nums{ 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << lengthOfLIS_1(nums);
	cout << lengthOfLIS_2(nums);
	getchar();
	return 0;
}