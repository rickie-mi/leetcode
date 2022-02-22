class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ss = nums[0], cnt = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == ss) cnt++;
            else if(cnt == 0){
                ss = nums[i];
                cnt++;
            }
            else
                cnt--;
        }
        return ss;
    }
};