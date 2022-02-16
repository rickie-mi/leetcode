//单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk; //存的是下标
        int ans = 0;
        for(int i=0; i<height.size(); i++)
        {
            if(stk.size()== 0 || height[stk.top()] >= height[i])
                stk.push(i);
            else
            {
                while(stk.size()>0 && height[stk.top()] < height[i])
                {
                    int tt = stk.top();
                    stk.pop();
                    if(stk.size()>0)  //必须是碗的形状
                    {
                        int hh = min(height[stk.top()], height[i]) - height[tt];
                        int dd = i-stk.top()-1;
                        ans += hh*dd;
                    }

                }
                stk.push(i);
            }
        }
        return ans;
    }
};

//双向dp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n,0), rightMax(n,0);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];
        for(int i=1; i<n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);
        for(int i=n-2; i>=0; i--)
            rightMax[i] = max(rightMax[i+1],height[i]);
        int ans =0;
        for(int i=0; i<n; i++)
            ans += min(leftMax[i],rightMax[i])-height[i];
        return ans;
    }
};

//双向dp优化（双指针）
class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        int leftMax=0, rightMax=0, ll=0, rr=n-1;
        int ans =0;
        while(ll<=rr)
        {
            leftMax = max(leftMax, height[ll]);
            rightMax = max(rightMax, height[rr]);
            if(leftMax > rightMax)
            {
                ans += rightMax-height[rr];
                rr--;
            }
            else
            {
                ans += leftMax-height[ll];
                ll++;
            }
        }
        return ans;
    }
};