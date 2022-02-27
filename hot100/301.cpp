class Solution {
private:
    vector<string> ans;
    stack<char> stk;
    int mincnt;
public:
    vector<string> removeInvalidParentheses(string s) {
        mincnt = INT_MAX;
        string mod = "";
        dfs(s,0,mod,0);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()),ans.end());
        return ans;
    }

    void dfs(string& s, int st, string& mod, int cnt){
        //cout<<mod<<' '<<cnt<<' '<<stk.size()<<endl;
        if(st == s.size())
        {
            if(stk.empty())
            {
                if(cnt < mincnt)
                {
                    mincnt = cnt;
                    ans.clear();
                    ans.push_back(mod);
                }
                else if(cnt == mincnt)
                {
                    ans.push_back(mod);
                }
            }
            return;
        }
        char c = s[st];
        if(c!='(' && c!=')')
        {
            mod.push_back(c);
            dfs(s,st+1,mod,cnt);
            mod.pop_back();
            return;
        }
        //不要这个符号
        dfs(s,st+1,mod,cnt+1);
        //要这个符号
        if(c=='(')
        {
            stk.push(c);
            mod.push_back(c);
            dfs(s,st+1,mod,cnt);
            mod.pop_back();
            stk.pop();
        }
        else
        {
            if(stk.size() && stk.top() == '(')
            {
                stk.pop();
                mod.push_back(c);
                dfs(s,st+1,mod,cnt);
                mod.pop_back();
                stk.push('(');
            }               
        }
    }
};