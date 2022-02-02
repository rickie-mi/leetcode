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
        for(int i = 1; i<=n; i++)
        {
            res = min(res, max(superEggDrop(k-1,i-1), superEggDrop(k,n-i))+1);
            //扔碎 下面i-1层
            //没碎 上面n-i层
        }
        mp[temp] = res;
        return res;
    }
};