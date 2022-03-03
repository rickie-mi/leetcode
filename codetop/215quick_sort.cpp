class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums,0, nums.size()-1,k);
    }

    int quick_sort(vector<int>& nums, int l, int r, int k){
        if(l==r) return nums[l];
        int i=l-1, j=r+1; unsigned int x = (l+r)>>1;
        while(i<j){
            do i++; while(nums[i]<nums[x]);
            do j--; while(nums[j]>nums[x]);
            if(i<j) swap(nums[i],nums[j]);
        }
        int s1 = r-j;
        if(k<=s1)  return quick_sort(nums,j+1,r,k);
        else  return quick_sort(nums,l,j,k-s1);
    }
};