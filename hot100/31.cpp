class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        //从后往前找到第一个降序的
        int i =n-1;
        while(i>0){
            if(nums[i-1] >= nums[i])
                i--;
            else
                break;
        }
        if(i==0){
            //表示原数组是最大的
            reverse(nums.begin(), nums.end());
            return;
        }
        int left = i-1;
        int j;
        for(j=n-1; j>left; j--){
            if(nums[j] > nums[left]){
                //替换掉后，后面依然是递减的序列，需要换成递增的
                swap(nums[j], nums[left]);
                //换成递增的
                reverse(nums.begin()+left+1, nums.end());
                return;
            }
        }
    }
};