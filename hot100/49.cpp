class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> back;
        for(auto c: strs) back.push_back(c);
        unordered_map<string, vector<int>> mp;
        int n = strs.size();
        for(int i=0; i<n; i++)
        {
            sort(back[i].begin(), back[i].end());
            mp[back[i]].push_back(i);
        }
        vector<vector<string>> res;
        for(auto &[key, value]: mp)
        {
            vector<string> temp;
            for(auto ss: value) temp.push_back(strs[ss]);
            res.push_back(temp);
        }
        return res;
    }
};