class Solution {
public:
    int hammingDistance(int x, int y) {
        int p = x^y;
        int ans = 0;
        while(p)
        {
            p -= p&(-p);
            ans++;
        }
        return ans;
    }
};