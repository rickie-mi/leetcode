class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]=i;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.count(target - nums[i]) && mp[target-nums[i]] != i)
                return vector<int>{i, mp[target-nums[i]]};
        }
        return vector<int>{};
    }
};