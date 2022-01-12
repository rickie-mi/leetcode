#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std; 

void sortColors(vector<int>& nums) {
	//[0,p1]表示0
	//(p1,i)表示1
	//[p2,len-1]表示2
	int p1 = -1, i = 0, p2 = nums.size(); //三个区间起始都为空
	while (i<p2)
	{
		if (nums[i] == 0)
		{
			p1++;
			swap(nums[i], nums[p1]);
			i++;
		}
		else if (nums[i] == 1)
		{
			i++;
		}
		else
		{
			p2--;
			swap(nums[i], nums[p2]);
		}
	}

}