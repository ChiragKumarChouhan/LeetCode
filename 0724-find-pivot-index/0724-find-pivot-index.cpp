class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int left=0;
        int right =0;
         if(sum - nums[0] == 0)
            return 0;
        for(int i=1;i<n;i++){
            left+=nums[i-1];//last to one 
          right=sum-nums[i]-left;
            if(left==right){
                return i;
            }
        }
        return -1;
    }
};