class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(maxsum(0,n-2,nums), maxsum(1,n-1,nums));
    }

    int maxsum(int left, int right, vector<int>& nums){
        int dp1 = nums[left], dp2 = 0;
        for(int i=left+1; i<=right; i++)
        {
            int temp = max(nums[i]+dp2, dp1);
            dp2 = dp1;
            dp1 = temp;
        }
        return dp1;
    }
};