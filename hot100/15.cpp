class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            twoSum(nums[i], i+1, n-1, nums, target);
        }
        return res;
    }
    void twoSum(int pre, int st, int ed, vector<int>& nums, int target){
        int ll=st, rr=ed;
        while(ll<rr)
        {
            if(ll>st && nums[ll]==nums[ll-1])
            {
                ll++; continue;
            }
            if(rr<ed && nums[rr]==nums[rr+1])
            {
                rr--;continue;
            }
            if(nums[ll]+nums[rr] == target)
                res.push_back(vector<int>{pre, nums[ll++], nums[rr--]});
            else if(nums[ll]+nums[rr] > target)
                rr--;
            else
                ll++;

        }
    }
};