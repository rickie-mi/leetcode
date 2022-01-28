class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) sum += num;
        if(sum%2) return false;
        int n = nums.size();
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++)
        {
            for(int j=sum; j>=1; j--)
            {
                if(j - nums[i-1] >= 0)
                    dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[sum];
    }
};