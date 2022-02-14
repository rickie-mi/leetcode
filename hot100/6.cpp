class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string res = "";
        int i=0;
        while(i<s.size())
        {
            res.push_back(s[i]);
            i+=2*(numRows-1);
        }
        for(i=1; i<numRows-1; i++)
        {
            int t = i;
            int cnt =1;
            while(t<s.size())
            {
                int j1=t, j2=cnt*(2*(numRows-1))-i;
                if(j1<s.size())
                    res.push_back(s[j1]);
                if(j2<s.size())
                    res.push_back(s[j2]);
                t+=2*(numRows-1);
                cnt++;
            }
        }
        i = numRows-1;
        while(i<s.size())
        {
            res.push_back(s[i]);
            i+=2*(numRows-1);
        }
        return res;
    }
};