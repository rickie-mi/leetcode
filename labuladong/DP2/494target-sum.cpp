class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto n: nums) sum += n;
        if(sum < abs(target) || (sum+target)%2 == 1)
            return 0;
        return subset(nums, (sum+target)/2);
    }

    int subset(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=target; j>=0; j--)
            {
                if(j-nums[i-1] >= 0)
                    dp[j] = dp[j-nums[i-1]] +  dp[j];
            }
        }
        return dp[target];
    }
};