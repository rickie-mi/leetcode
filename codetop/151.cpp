class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0, end = n-1;
        while(start<n && s[start]==' ') start++;
        while(end>=0 && s[end]==' ') end--;
        if(start==n) return "";
        int i=0, j=start;
        while(j<=end)
        {
            if(s[j]!=' ')
                s[i++] = s[j++];
            else
            {
                s[i++] =s[j++];
                while(j<=end && s[j]==' ') j++;
            }
        }
        int len = i;
        reverse(s.begin(), s.begin()+len);
        for(i=0; i<len; i++)
        {
            j=i;
            while(j<len &&s[j]!=' ') j++;
            reverse(s.begin()+i, s.begin()+j);
            i=j;
        }
        return s.substr(0,len);
    }
};