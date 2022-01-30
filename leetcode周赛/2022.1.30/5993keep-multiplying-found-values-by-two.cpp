class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        //排序
        sort(nums.begin(), nums.end());
        while(true)
        {   
            //二分查找
            int ll = 0, rr = nums.size()-1;
            while(ll<rr)
            {
                int mid = (ll+rr)>>1;
                if(nums[mid] >= original)
                    rr = mid;
                else
                    ll = mid+1;
            }
            if(nums[ll] == original)
                original *= 2;
            else
                break;
        }
        return original;
    }
};
