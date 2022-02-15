class Solution {
private:
    vector<vector<char>> mp;;
public:
    vector<string> letterCombinations(string digits) {
        mp.resize(10);
        mp[2] = vector<char>{'a','b','c'};
        mp[3] = vector<char>{'d','e','f'};
        mp[4] = vector<char>{'g','h','i'};
        mp[5] = vector<char>{'j','k','l'};
        mp[6] = vector<char>{'m','n','o'};
        mp[7] = vector<char>{'p','q','r','s'};
        mp[8] = vector<char>{'t','u','v'};
        mp[9] = vector<char>{'w','x','y','z'};
        vector<string> res;
        string temp ="";
        backtrace(digits,0,temp,res);
        return res;
    }

    void backtrace(string &digits, int st, string &temp, vector<string>&res){
        if(st == digits.size())
        {
            if(temp != "")
                res.push_back(temp);
            return;
        }
        int dig = digits[st]-'0';
        for(auto c: mp[dig]){
            temp.push_back(c);
            backtrace(digits, st+1, temp, res);
            temp.pop_back();
        }
    }
};