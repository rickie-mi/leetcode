class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        dfs(1, k, n, temp);
        return ans;
    }
    void dfs(int st, int k, int n, vector<int>& temp)
    {
        if(st == n+1)
        {
            if(temp.size() == k)
                ans.push_back(temp);
            return;
        } 
        dfs(st+1,k,n,temp);
        temp.push_back(st);
        dfs(st+1,k,n,temp);
        temp.pop_back();
    }
};