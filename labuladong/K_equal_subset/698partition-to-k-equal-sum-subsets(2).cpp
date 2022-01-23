class Solution {
private:
    unordered_map<int,bool> memo;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        for(auto num: nums) target += num;
        if(target%k != 0) return false;   //不能整除肯定不行
        target /= k;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());  //从大到小排序，可以提前结束某些分支
        if(target < nums[0]) return false;  //第一个值太大，大于平均值也不行
        int n = nums.size();
        int isput = 0;
        return backtrace(k, 0, 0, target, nums, isput);
    }

    bool backtrace(int k, int st, int cur, int target, vector<int>& nums, int isput)
    {
        if(k == 0) return true;
        if(target == cur)
        {
            bool res = backtrace(k-1,0,0,target,nums,isput);
            memo[isput] = res;
            return res;          
        }
        if(memo.count(isput) != 0)
            return memo[isput];
        for(int i=st; i<nums.size(); i++)
        {
            int c = nums[i];
            if(((isput>>i) & 1) == true)
                continue;
            if(cur + c > target) 
                continue;
            cur += c;
            isput = isput | (1<<i);
            if(backtrace(k, i+1, cur, target, nums, isput))   //不能直接return
                return true;
            isput = isput ^ (1<<i);
            cur -= c;
        }
        return false;
    }
};