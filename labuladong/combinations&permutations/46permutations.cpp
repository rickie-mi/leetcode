class Solution {
private:
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    int n;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        n = nums.size();
        for(auto num: nums) mp[num] = 0;
        dfs(temp,0);
        return ans;
    }

    void dfs(vector<int> &temp, int cnt)
    {
        if(cnt == n)
        {
            ans.push_back(temp);
            return;
        }
            
        for(auto &[key, value] : mp)
        {
            if(value == 0)
            {
                temp.push_back(key);
                mp[key] = 1;
                dfs(temp, cnt+1);
                mp[key] = 0;
                temp.pop_back();
            }
        }
    }
};