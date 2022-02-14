class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int i=0, j=0, n=s.size();
        int st = -1, len = INT_MIN;
        while(i<n)
        {
            char c=s[i++];
            window[c]++;
            if(window[c]<=1)
            {
                if(i-j>len)
                {
                    st = j;
                    len = i-j;
                }
            }
            else
            {
                while(window[c]>1)
                {
                    char sc = s[j];
                    window[sc]--;
                    j++;
                }
            }
        }
        return len == INT_MIN? 0: len;
    }
};