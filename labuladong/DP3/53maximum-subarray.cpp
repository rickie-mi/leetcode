class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int pre = nums[0];
        int res = pre;
        for(int i=1; i<n; i++)
        {
            pre = max(pre+nums[i], nums[i]);
            res = max(res, pre);
        }
        return res;
    }
};