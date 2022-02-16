class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ll=0, rr=n-1;
        while(ll<=rr)
        {
            int mid = (ll+rr)>>1;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[0]) //左边有序
            {
                if(nums[0]<=target && nums[mid]>target)
                    rr=mid-1;
                else
                    ll=mid+1;
            }
            else
            {   
                if(nums[n-1]>=target && nums[mid]<target)
                    ll=mid+1;
                else
                    rr=mid-1;
            }
        }
        return -1;
    }
};