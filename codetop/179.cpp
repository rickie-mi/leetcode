class Solution {
static bool cmp(const int a, const int b){
    string sa=to_string(a), sb=to_string(b);
    return (sa+sb)>(sb+sa);
}
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(),cmp);
        if(nums[0]==0) return "0";
        string ans="";
        for(int num:nums)
        {
            ans += to_string(num);
        }
        return ans;
    }
};