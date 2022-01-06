#include <iostream>
#include <vector>
using namespace std; 

class NumArray {
private:
    vector<int> tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        tree.resize(n * 2);
        for (int i = n; i < 2 * n; i++)
            tree[i] = nums[i - n];
        for (int i = n - 1; i > 0; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    void update(int index, int val) {
        int idx = index + n;
        tree[idx] = val;
        while (idx > 0)
        {
            int left = idx;
            int right = idx;
            if (idx % 2 == 0)//idx «◊Û≤‡
                right = idx + 1;
            else //idx «”“≤‡
                left = idx - 1;
            idx /= 2;
            tree[idx] = tree[left] + tree[right];
        }
    }

    int sumRange(int left, int right) {
        left = left + n;
        right = right + n;
        int ans = 0;
        while (left <= right)
        {
            if (left % 2 == 1)
            {
                ans += tree[left];
                left++;
            }
            if (right % 2 == 0)
            {
                ans += tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */