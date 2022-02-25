class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int n = nums.size();
        for(int i =0 ; i<n; i++){
            while(q.size() && i-q.front()+1>k) q.pop_front();
            while(q.size() && nums[q.back()]<=nums[i]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};