class Solution {
public:
    string validIPAddress(string queryIP) {
        if(checkIP4(queryIP))
            return "IPv4";
        if(checkIP6(queryIP))
            return "IPv6";
        return "Neither";
    }
    bool checkIP4(string s){
        int cnt=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                int num=0;
                if(s[i]=='0' && (i+1<s.size() && s[i+1]!='.'))
                    return false;
                int j=i;
                while(j<s.size()&&s[j]!='.')
                {
                    if(s[j]<'0' || s[j]>'9') return false;
                    num = num*10+(s[j]-'0');
                    j++;
                    //cout<<num<<endl;
                    if(num>255) return false;
                }
                if(j<s.size() && cnt==3) return false;
                i=j;cnt++;
            }
            else return false;
        }
        if(cnt==4) return true;
        else return false;
    }

    bool checkIP6(string s){
        int cnt = 0;
        string temp="";
        int cur=0;
        while(cur<s.size())
        {
            if(s[cur]==':')
            {
                if(temp.size()<1 || temp.size()>4) return false;
                temp="";
                cur++; cnt++;
                continue;
            }
            if((s[cur]>='0'&&s[cur]<='9') ||(s[cur]>='A'&&s[cur]<='F')||(s[cur]>='a'&&s[cur]<='f'))
            {
                temp.push_back(s[cur]);
                cur++;
                continue;
            }
            return false;
        }
        if(temp.size()>=1&&temp.size()<=4 && cnt==7)return true;
        else return false;
    }
};