class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum%2==1) return ans;
        long long cur = 2;
        while(finalSum>= cur)
        {
            ans.push_back(cur);
            finalSum -= cur;
            cur += 2;
        }
        if(finalSum == 0) return ans;
        else
        {
            
            ans[ans.size()-1] += finalSum;
            return ans;
        }
    }
};