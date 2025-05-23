class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int left=0;
      int right=nums.size()-1;
      while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
        return mid;
        else if(target<nums[mid])
        right=mid-1;
        else
        left=mid+1;
      }  
      return left;
    }
};
/*
int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target)
            return mid;
            else if(target<nums[mid]){
                end=mid-1;
            }
            else start=mid+1;
        }
        return end+1;
        */