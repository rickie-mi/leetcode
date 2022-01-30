class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        vector<long long> poweridx{1};
        long long cur = 1;
        for(int i=1; i<k; i++)
        {
            cur = cur*power%modulo;
            poweridx.push_back(cur);
        }
        int n = s.size();
        for(int i=0; i+k<=n; i++)
        {
            long long res = 0;
            for(int j=0; j<k; j++)
            {
                long long temp = (s[i+j]-'a'+1);
                res = ((temp*poweridx[j])%modulo + res)%modulo;
            }
            if(res == hashValue)
                return  s.substr(i, k);
        }
        return  "";
    }
    
};