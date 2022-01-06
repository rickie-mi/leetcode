#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        //vector<int> presum(n+1, 0);  这里就不需要一个单独的数组去存储前缀和了
        int presum = 0;
        mp[0]++;
        for (int i = 0; i < n; i++)
        {
            presum += nums[i];
            ans += mp[presum - k];
            mp[presum]++;
        }
        return ans;
    }
};