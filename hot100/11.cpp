class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ll=0, rr=n-1;
        int res = -1; 
        while(ll<rr){
            res = max(res, min(height[ll],height[rr])*(rr-ll) );
            if(height[ll]<height[rr])
                ll++;
            else
                rr--;
        }
        return res;
    }
};