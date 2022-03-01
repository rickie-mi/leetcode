class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int right = -1, left = -1;
        int n =nums.size();
        int maxn = INT_MIN, minn = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(nums[i]>=maxn)
                maxn = nums[i];
            else 
                right = i;
            if(nums[n-1-i] <= minn)
                minn = nums[n-1-i];
            else
                left = n-1-i;
        }
        return right==-1?0:right-left+1;
    }
};