class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int ans=-1;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[n-1]){
                //search in right
                low=mid+1;

            }else{
                ans =nums[mid];//should return index
                high=mid-1;
            }
        }
        return ans;
    }
};