class Solution {
public:
 int firstOccurrence(vector<int>& nums, int target){
    int n=nums.size();
    int high=n-1;
    int low=0;
    int result=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]<target){
            low=mid+1;
        }else if(nums[mid]>target){
            high=mid-1;
        }else{
            result=mid;
            high=mid-1;
        }
       
    }
     return result;
 }
 int lastOccurrence(vector<int>& nums, int target){
    int n=nums.size();
    int high=n-1;
    int low=0;
    int result=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]<target){
            low=mid+1;
        }else if(nums[mid]>target){
            high=mid-1;
        }else{
            result=mid;
            low=mid+1;
        }
       
    }
     return result;
 }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first= firstOccurrence(nums,target);
        int last=lastOccurrence(nums,target);
        return {first,last};
    }
};