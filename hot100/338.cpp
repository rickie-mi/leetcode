class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<n+1; i++)
        {
            ans.push_back(getbit(i));
        }
        return ans;
    }
    int getbit(int n){
        int ans = 0;
        while(n){
            n -= n&(-n);
            ans++;
        }
        return ans;
    }
};