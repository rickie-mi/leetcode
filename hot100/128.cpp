class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> set;
        for(auto c: nums) set.insert(c);
        int maxlen = 1;
        for(auto c: set)
        {
            if(set.count(c-1)) continue;
            int curlen = 0;
            while(set.count(c++)) curlen++;
            maxlen = max(maxlen, curlen);
        }
        return maxlen;
    }
};