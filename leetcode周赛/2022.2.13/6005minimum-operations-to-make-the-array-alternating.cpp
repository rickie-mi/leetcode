typedef pair<int, int> PII;
class Solution {
public:
    static bool cmp(PII a, PII b){
        return a.second > b.second;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;  //一个数字
        unordered_map<int,int> mp1, mp2;
        int cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(i%2==0){ mp1[nums[i]]++; cnt1++;}
            if(i%2==1){ mp2[nums[i]]++; cnt2++;}
        }
        vector<PII> vt1, vt2;
        for(auto &[key, value]: mp1) vt1.push_back({key,value});
        for(auto &[key, value]: mp2) vt2.push_back({key,value});
        sort(vt1.begin(), vt1.end(), cmp);
        sort(vt2.begin(), vt2.end(), cmp);
        if(vt1[0].first != vt2[0].first)
            return n-(vt1[0].second+vt2[0].second);
        else if(vt1.size() == 1 && vt2.size() == 1)
            return min(cnt1, cnt2);
        else if(vt1.size() == 1)
            return min(cnt2-vt2[1].second, cnt1+cnt2-vt2[0].second);
        else if(vt2.size() == 1)
            return min(cnt1-vt1[1].second, cnt2+cnt1-vt1[0].second);
        else
            return min(n-vt1[0].second-vt2[1].second, n-vt2[0].second-vt1[1].second);
            
    }
};