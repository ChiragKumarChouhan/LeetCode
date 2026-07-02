class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
      unordered_map<int, int> mp;
        mp[0]=1;
        int result=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];//sum is calculated
            int rem=((sum%k)+k)%k;//can solve any positive and negative value 
            result+=mp[rem];
            mp[rem]++;

        }
        return result;
    }
};