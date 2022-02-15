class Solution {
private:
    string temp;
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        dfs(n,n);
        return ans;
    }

    void dfs(int left, int right){
        if(left==0 && right==0)
        {
            ans.push_back(temp);
            return;
        }
        if(left==0) 
        {
            temp.push_back(')');
            dfs(left, right-1);
            temp.pop_back();
        }
        else
        {
            if(left<right)
            {
                temp.push_back(')');
                dfs(left,right-1);
                temp.pop_back();
            }
            
            temp.push_back('(');
            dfs(left-1,right);
            temp.pop_back();
        }
    }
};