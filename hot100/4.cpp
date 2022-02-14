class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n=nums2.size();
        if((m+n)%2==1)
            return getK(nums1,nums2,(m+n+1)/2);
        else
            return (getK(nums1,nums2,(m+n)/2)+getK(nums1,nums2,(m+n)/2+1))/2.0;
    }
    int getK(vector<int>& nums1, vector<int>& nums2, int k){
        int m = nums1.size(), n=nums2.size();
        int idx1=0,idx2=0;
        while(true)
        {
            if(idx1==m) return nums2[idx2+k-1];
            if(idx2==n) return nums1[idx1+k-1];
            if(k==1) return min(nums1[idx1],nums2[idx2]);
            int t1=min(idx1+k/2-1, m-1);
            int t2=min(idx2+k/2-1, n-1);
            if(nums1[t1]<nums2[t2])
            {
                k -= t1-idx1+1;
                idx1 = t1+1;
            }
            else
            {
                k-= t2-idx2+1;
                idx2 = t2+1;
            }
        }
    }
};