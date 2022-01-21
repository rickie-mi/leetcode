class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        ans.push_back(temp);
        backtrace(0,n, temp,nums);
        return ans;
    }
    void backtrace(int st, int n, vector<int> &temp, vector<int>& nums)
    {
        if(st==n) return;
        //不加
        backtrace(st+1, n, temp, nums);
        //加
        temp.push_back(nums[st]);
        ans.push_back(temp);
        backtrace(st+1, n, temp, nums);
        temp.pop_back();
    }
};