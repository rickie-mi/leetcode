class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size(); 
        if(n==1) return 0;
        int ll=0, rr=n-1;
        while(ll<rr)
        {
            int mid = ll+(rr-ll)/2;
            if(mid==n-1) return mid;
            if(nums[mid]<nums[mid+1]) ll=mid+1;
            else rr=mid;
        }
        return ll;
    }
};