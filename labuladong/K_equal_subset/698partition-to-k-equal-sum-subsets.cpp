class Solution {
private:
    bool flag;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        for(auto num: nums) target += num;
        if(target % k) return false;
        target /= k;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        if(nums[0] > target) return false;
        vector<bool> bucket(nums.size(), false);
        flag = false;
        backtrace(k,0,0,target,nums, bucket);
        return flag; 
    }

    void backtrace(int k, int st, int cur, int target, vector<int> &nums, vector<bool> &bucket)
    {
        if(flag) return;
        if(k==0)
        {
            flag = true;
            return;
        }
        if(cur == target)
        {
            backtrace(k-1, 0, 0, target, nums, bucket);
        }
        int n = nums.size();
        for(int i=st; i<n && !flag; i++)
        {
            int c = nums[i];
            if(bucket[i]) continue;
            if(c + cur > target) continue;
            cur += c;
            bucket[i] = true;
            backtrace(k, i+1, cur, target, nums, bucket);
            cur -= c;
            bucket[i] = false;
        }
    }
};