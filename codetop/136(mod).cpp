class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n==1) return nums[0];
        int ll=0, rr=n-1;
        while(ll<=rr)
        {
            if(ll==rr) return nums[ll];
            int mid=ll+(rr-ll)/2;
            if((mid==n-1||nums[mid]!=nums[mid+1])&&(mid==0||nums[mid]!=nums[mid-1]))
                return nums[mid];
            int mid2;
            if((mid>0 && nums[mid]==nums[mid-1]) || mid==n-1)
            {
                mid2=mid-1;
                if(mid2%2==1) rr=mid2-1;
                else ll=mid+1;
            }
            if((mid<n-1 && nums[mid]==nums[mid+1]) || mid==0) 
            {
                mid2=mid+1;
                if(mid%2==1) rr=mid-1;
                else ll=mid2+1;
            }

        }
        return -1;
    }
};