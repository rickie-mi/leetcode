class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> item;
        string temp = "";
        for(int i=0; i<n; i++){
            if(path[i] == '/'){
                if(temp != "")
                    item.push_back(temp);
                temp = "";
            }
            else
                temp.push_back(path[i]);
        }
        if(temp != "")
            item.push_back(temp);
        stack<string> stk;
        //for(auto c: item) cout<<c<<endl;
        for(auto c: item){
            if(c == ".") continue;
            if(c == "..")
            {
                if(stk.size()) stk.pop();
            }               
            else stk.push(c);
        }
        string ans="";
        while(stk.size())
        {
            ans = "/"+stk.top()+ans;
            stk.pop();
        }
        return ans == "" ? "/": ans;
    }
};