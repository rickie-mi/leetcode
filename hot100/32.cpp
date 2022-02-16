//法一 双指针
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0) return 0;
        //双指针（匹配就是右边数量=左边数量，且中间不存在右边数量>左边数量）
        int ll=0,rr=0, maxans=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(') ll++;
            else rr++;
            if(ll==rr) maxans = max(maxans, ll+rr);
            else if(rr>ll) {ll=0; rr=0;}
        }
        ll=0;rr=0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]==')') rr++;
            else ll++;
            if(ll==rr) maxans = max(maxans, ll+rr);
            else if(ll>rr) {ll=0; rr=0;}
        }
        return maxans;
    }
};

//法二 dp
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0) return 0;
        vector<int> dp(n,0);
        int maxans=0;
        for(int i=1; i<n; i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(') 
                    dp[i] = i>=2?dp[i-2]+2:2;
                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
                    dp[i] = dp[i-1]+2+(i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2]:0);
                maxans = max(maxans,dp[i]);
            }
        }
        return maxans;
    }
};