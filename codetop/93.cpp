class Solution {
private:
    vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> temp;
        dfs(s,0,temp);
        return ans;
    }
    void dfs(string& s, int st, vector<int>&temp){
        if(st==s.size())
        {
            if(temp.size()==4)
            {
                string res = "";
                for(int i=0; i<3; i++) res+=to_string(temp[i])+".";
                res+=to_string(temp[3]);
                ans.push_back(res);
            }
            return;
        }
        if(temp.size()>=4) return;
        if(s[st]=='0')
        {
            temp.push_back(0);
            dfs(s,st+1,temp);
            temp.pop_back();
        }
        else
        {
            int num = s[st]-'0';
            temp.push_back(num);
            dfs(s,st+1,temp);
            temp.pop_back();
            if(st+1<s.size())
            {
                num = num*10+s[st+1]-'0';
                temp.push_back(num);
                dfs(s,st+2,temp);
                temp.pop_back();
            }
            if(st+2<s.size())
            {
                num = num*10+s[st+2]-'0';
                if(num<=255)
                {
                    temp.push_back(num);
                    dfs(s,st+3,temp);
                    temp.pop_back();
                }               
            }
        }
    }
};