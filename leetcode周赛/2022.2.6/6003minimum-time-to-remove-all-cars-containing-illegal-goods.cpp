class Solution {
public:
    int minimumTime(string s) {
        //前后缀dp
        int n = s.size();
        vector<int> suf(n);
        for(int i=n-1; i>=0; i--)
        {
            if(i == n-1) 
                suf[i] = s[i]=='0'? 0:1;
            else
                suf[i] = s[i]=='0'? suf[i+1]:min(suf[i+1]+2,n-i);
        }
        int pre=0;
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        {
            pre = s[i]=='0'?pre:min(pre+2,i+1); 
            if(i<n-1)
                ans = min(ans, pre+suf[i+1]);
            else
                ans = min(ans,pre);
        }
        return ans;
    }
};