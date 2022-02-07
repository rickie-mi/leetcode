class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        /*
        int p1=0, i=0, p2=nums.size()-1;
        while(i<=p2){
            if(nums[i]<pivot){
                swap(nums[i],nums[p1]);
                p1++;
                i++;
            }
            else if(nums[i] == pivot){
                i++;
            }
            else if(nums[i]>pivot){
                swap(nums[i],nums[p2]);
                //swap(nums[p2],)
                p2--;
            }
        }
        int i1=p2+1, i2=nums.size()-1;
        while(i1<=i2){
            swap(nums[i1], nums[i2]);
            i1++; i2--;
        }
        return nums;
    
    */
      vector<int> lower;
      vector<int> higher;
      int cnt = 0;
      for(int i=0; i<nums.size();i++){
          if(nums[i]<pivot) lower.push_back(nums[i]);
          else if(nums[i]>pivot) higher.push_back(nums[i]);
          else cnt++;
      }
      vector<int> mid(cnt,pivot);
      lower.insert(lower.end(), mid.begin(), mid.end());
      lower.insert(lower.end(), higher.begin(), higher.end());
      return lower;
    }
};