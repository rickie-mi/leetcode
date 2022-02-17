class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int maxlen = nums[0];
        for(int i=1; i<n; i++)
        {
            if(maxlen<i) return false;
            maxlen = max(maxlen, nums[i]+i);
            if(maxlen >= n) return true;
        }
        return true;
    }
};