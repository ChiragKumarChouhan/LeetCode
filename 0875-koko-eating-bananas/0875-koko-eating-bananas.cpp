class Solution {
public:
    long long fun(vector<int>& a, int speed) {
        int n = a.size();
        long long h = 0;
        for (int i = 0; i < n; i++) {
            h = h + a[i] / speed;
            if(a[i]%speed!=0){ // mean h is not fully divided by speed mean it should increase by 1
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int result=-1;
        int high= *max_element(piles.begin(), piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hourse=fun(piles,mid);
            if(hourse>h){
                //search in right
                low=mid+1;
            }else{
                result=mid;
                high=mid-1;
            }
        }
        return result;
    }
};