class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int maxans = 0;
        vector<int> temp(cols+1, 0);
        stack<int> stk;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<= cols; j++)
            {
                if(j<cols) temp[j] = (matrix[i][j]=='0')?0:(temp[j]+1);
                while(stk.size()>0 && temp[j]<temp[stk.top()])
                {
                    int hh = stk.top();
                    stk.pop();
                    maxans = max(maxans, temp[hh]*(stk.empty()?j:(j-stk.top()-1)));
                }
                stk.push(j);
            }
            while(stk.size())stk.pop();
        }
        return maxans;
    }
};