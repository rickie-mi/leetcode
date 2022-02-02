class Solution {
private:
    unordered_map<int, int> mp;
public:
    int superEggDrop(int k, int n) {
        if(n == 0) return 0;   //没有楼不需要检测
        if(k == 1) return n;   //一个鸡蛋，只能逐一排查
        int temp = k*1e5+n;
        if(mp.count(temp)) return mp[temp];
        int res = INT_MAX;
        //用二分法去查找山谷值
        int ll=1, rr=n;
        while(ll<=rr)
        {
            int mid = (ll+rr)>>1;
            int not_broken = superEggDrop(k,n-mid);
            int broken = superEggDrop(k-1,mid-1);
            if(not_broken > broken)
            {
                ll = mid+1;
                res = not_broken + 1;
            }
            else if(not_broken < broken)
            {
                rr = mid-1;
                res = broken + 1;
            }
            else
            {
                res = not_broken + 1;
                break;
            }
        }
        
        mp[temp] = res;
        return res;
    }
};