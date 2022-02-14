class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int st=intervals[0][0], ed=intervals[0][1];
        for(auto &c: intervals)
        {
            if(c[0]<=ed){
                if(c[1]>ed) ed = c[1];
            }
            else{
                res.push_back(vector<int>{st,ed});
                st=c[0]; ed=c[1];
            }
        }
        res.push_back(vector<int>{st,ed});
        return res;
    }
};