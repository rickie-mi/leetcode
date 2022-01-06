#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    //vector<int> nums;
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.push_back(0);
        for (int i = 0; i < n; i++)
        {
            //this->nums.push_back(nums[i]);
            sums.push_back(sums[i] + nums[i]);
        }


    }

    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
};