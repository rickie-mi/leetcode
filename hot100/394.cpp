//法一
class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        int cnt=0; 
        string cur="";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>='0'&&s[i]<='9') cnt=cnt*10+s[i]-'0';
            else if(s[i]>='a'&&s[i]<='z') cur.push_back(s[i]);
            else if(s[i]=='[')
            {
                nums.push(cnt);
                strs.push(cur);
                cnt=0; cur="";
            }
            else if(s[i]==']')
            {
                int k = nums.top();
                nums.pop();
                string temp = strs.top();
                strs.pop();
                for(int i=0; i<k; i++) temp+=cur;
                cur = temp;
            }
        }
        return cur;
    }
};

