class Solution {
private:
    unordered_map<string, bool> mp;
public:
    bool isMatch(string s, string p) {
        return dp(s,0,p,0);
    }
    bool dp(string &s, int i, string &p, int j)
    {
        //base case
        int n = s.size(), m = p.size();
        if(j == m)
        {
            return i == n;
        }
        if(i == n)
        {
            //后续只能是 x*y*z*这种间隔的格式
            if((m-j)%2 == 1)
                return false;
            for(; j+1<m; j+=2)
            {
                if(p[j+1] != '*')
                    return false;
            }
            return true;
        }
        string temp = to_string(i)+","+to_string(j);
        if(mp.count(temp)) return mp[temp];
        bool res = false;
        if(s[i] == p[j] || p[j] == '.')
        {
            if(j+1<m && p[j+1] == '*')
            {
                res = dp(s,i,p,j+2)  || dp(s,i+1,p,j); //匹配0次和匹配多次 
            }
            else
                res = dp(s,i+1,p,j+1);
        }
        else
        {
            if(j+1<m && p[j+1] == '*')
            {
                res = dp(s,i,p,j+2); //只能匹配0次
            }
            else
                res = false;
        }
        mp[temp] = res;
        return res;
    }
};