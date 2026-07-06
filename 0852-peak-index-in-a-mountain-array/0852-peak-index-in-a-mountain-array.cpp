class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[mid + 1]) {
                // search on right
                low = mid + 1;
            } else  {
                ans=mid;
                high = mid; // mid could be the high point

            } 
             
        }
        
        return ans;
    }
};