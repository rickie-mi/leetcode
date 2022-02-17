class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n= heights.size();
        stack<int> stk;
        int area = 0;
        for(int i=0; i<n; i++)
        {
            while(stk.size()>0 && heights[stk.top()]>heights[i])
            {
                int hh = stk.top();
                stk.pop();
                area = max(area, heights[hh]*(stk.empty()?i:(i-stk.top()-1)));
            }
            stk.push(i);
        }
        return area;
    }
};