class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd,even;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        vector<int> ans(nums.size());
        for(int i=0; i<=nums.size()/2;i++)
        {
            if(i<even.size())ans[i*2] = even[i];
            if(i<odd.size())ans[i*2+1] = odd[i];
        }
        return ans;
    }
};