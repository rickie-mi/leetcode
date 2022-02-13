//法一
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        if(n == 1) return 0;
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for(auto c: beans) sum+=c;
        long long res = LONG_LONG_MAX;
        for(int i=0; i<n; i++){
            res = min(res, sum-beans[i]*(n-i));
        }
        return res;
    }
};
//法二
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long res = LONG_LONG_MAX;
        int n = beans.size();
        long long left=0, right=0;
        for(auto c: beans) right = (long long)c + right;
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n && beans[j] == beans[i])
                j++;
            right -= (long long)(j-i)*beans[i];
            if(right == 0)
                res = min(res, left);
            else
                res = min(res, left+right-(long long)(n-j)*beans[i]);
            //cout<<left<<' '<<right<<endl;
            left += (long long)(j-i)*beans[i];
            i = j;
            
        }
        return res;
    }
};