class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> dp(n);
        for(int i=n-1; i>=0; i--)
        {
            while(stk.size() && temperatures[stk.top()] <= temperatures[i])
                stk.pop();
            if(stk.size() == 0)
                dp[i] = 0;
            else
                dp[i] = stk.top()-i;
            stk.push(i);
        }
        return dp;
    }
};