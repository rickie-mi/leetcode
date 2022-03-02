class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0; i<n; i++)
        {
            res += palindrom(i,i,s);
            res += palindrom(i,i+1,s);
        }
        return res;
    }

    int palindrom(int left, int right, string& s){
        int res = 0;
        while(left>=0 && right<s.size() && s[left] == s[right])
        {
            res++;
            left--; right++;
        }
        return res;
    }

};