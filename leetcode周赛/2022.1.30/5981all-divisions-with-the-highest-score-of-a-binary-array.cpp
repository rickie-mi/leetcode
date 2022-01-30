class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int allone = 0, allzero = 0;
        int n = nums.size();
        for(int num: nums)
        {
            if(num == 0)
                allzero++;
            else
                allone++;
        }
        //先确定边界
        int maxnum = allone;
        vector<int> res{0};
        //定义一个指针往后移动
        int leftzero = 0;
        int rightone = allone;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
                leftzero++;
            else
                rightone--;
            if(leftzero+rightone > maxnum)
            {
                maxnum = leftzero + rightone;
                res.clear();
                res.push_back(i+1);
            }
            else if(leftzero+rightone == maxnum)
            {
                res.push_back(i+1);
            }
        }
        return res;
    }
};