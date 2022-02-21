class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<string>> dp(n+1);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if((dp[j].size() || j==0) && wordSet.count(s.substr(j,i-j))){
                    //cout<<i<<" "<<j;
                    if(dp[j].size() == 0) dp[i].push_back(s.substr(j,i-j));
                    else{
                        for(auto tt: dp[j])
                            dp[i].push_back(tt+" "+s.substr(j,i-j));
                    }
                }
            }
        }
        return dp[n];
    }
};