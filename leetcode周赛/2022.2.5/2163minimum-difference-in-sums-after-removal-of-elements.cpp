class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size()/3;
        vector<long long> minpre(nums.size(),-1);
        vector<long long> maxsuf(nums.size(),-1);
        priority_queue<int> pq1;
        long long psum = 0;
        for(int i=0; i<n; i++)
        {
            pq1.push(nums[i]);
            psum += nums[i];
        }
        minpre[n-1] = psum;    
        for(int i=n; i<3*n;i++)
        {
            if(nums[i]<pq1.top())
            {
                psum -= pq1.top();
                psum += nums[i];
                pq1.pop();
                pq1.push(nums[i]);
            }
            minpre[i] = psum;
        }
        //for(auto c: minpre) cout<<c;
        //cout<<endl;
        priority_queue<int,vector<int>,greater<int>> pq2;
        long long sufsum = 0;
        for(int i=3*n-1; i>=2*n; i--)
        {
            sufsum += nums[i];
            pq2.push(nums[i]);
        }
        maxsuf[2*n] = sufsum;
        for(int i=2*n-1; i>=0; i--)
        {
            if(nums[i]>pq2.top())
            {
                sufsum -= pq2.top();
                sufsum += nums[i];
                pq2.pop();
                pq2.push(nums[i]);
            }
            maxsuf[i] = sufsum;
        }
        //for(int c: maxsuf) cout<<c;
        //cout<<endl;
        long long ans = LONG_LONG_MAX;
        for(int i=n-1; i<2*n; i++)
            ans = min(ans,minpre[i]-maxsuf[i+1]);// cout<<i<<","<<minpre[i]<<","<<maxsuf[i+1]<<","<<endl;
        return ans;
    }
};