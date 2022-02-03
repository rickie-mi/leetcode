class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+2; j<n; j++)
            {
                for(int k=i+1; k<j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+nums[i]*nums[j]*nums[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};


/*
class Solution {
private:
    unordered_map<string, int> memo;
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        return dp(0,nums,visited);
    }

    int dp(int cnt, vector<int> &nums, vector<bool> &visited)
    {
        if(cnt == nums.size())
            return 0;
        string temp = "";
        for(int i=0; i<nums.size(); i++)
        {
            temp += to_string(visited[i])+",";
        }
        if(memo.count(temp)) return memo[temp];
        int res = 0, pre=1, post=1;
        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                int j = i+1;
                while(j<nums.size() && visited[j] ==true)
                    j++;
                if(j == nums.size())
                    post = 1;
                else
                    post = nums[j];
                int tt = pre*post*nums[i] + dp(cnt+1, nums,visited);
                res = max(res, tt);
                visited[i] = false;
                pre = nums[i]; 
            }
        }
        memo[temp] = res;
        return res;
    }
};
*/