//法一
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            int temp = 0;
            for(int j=i-2; j>=0; j--)
                temp = max(temp, dp[j]);
            dp[i] = temp + nums[i];
        }
        int res = -1;
        for(int i=0; i<n; i++)
            res = max(res, dp[i]);
        return res;
    }
};
//法二
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            if(i>=2)
                dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            else
                dp[i] = max(nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};
//法二优化
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp2 = 0, dp1 = nums[0];
        for(int i=1; i<n; i++)
        {
            int temp = max(dp1, nums[i]+dp2);
            dp2 = dp1;
            dp1 = temp;
        }
        return dp1;
    }
};