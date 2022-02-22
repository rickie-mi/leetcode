typedef pair<int,int> PII;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for(int i=1; i<n; i++){
            int ax = maxF, in = minF;
            maxF = max(ax*nums[i], max(in*nums[i],nums[i]));
            minF = min(ax*nums[i], min(in*nums[i],nums[i]));
            ans = max(ans, maxF);
        }
        return ans;
    }
};