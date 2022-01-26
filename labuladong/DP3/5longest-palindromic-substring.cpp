class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        for(int i=0; i<n; i++)
        {
            string temp1 = palindrome(i,i,s);
            string temp2 = palindrome(i,i+1,s);
            string temp = temp1.size() > temp2.size() ? temp1 : temp2;
            if(ans.size() < temp.size()) ans = temp;
        }
        return ans;
    }
    string palindrome(int l, int r, string & s)
    {
        while(l>=0 && r<s.size() && s[l]== s[r])
        {
            l--; r++;
        }
        return s.substr(l+1, r-l-1);  //[l+1, r-1]
    }
};