class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> dq;
        for(auto c: num){
            while(dq.size() && dq.back()>c && k){
                k--;
                dq.pop_back();
            }
            dq.push_back(c);
        }
        while(k--) dq.pop_back();
        while(dq.size()>1 && dq.front()=='0') dq.pop_front();
        string ans = "";
        for(auto c: dq)  ans+=c;
        if(ans=="") return "0";
        else return ans;

    }
};