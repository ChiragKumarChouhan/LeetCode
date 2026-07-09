class Solution {
public:
    long long  fun(vector<int>& a,int speed) { // make a function that return in long long 
        int n = a.size();
       long long   h = 0;  // take it as long long 
        for (int i = 0; i < n; i++) {
            h = h + a[i] / speed;
            if (a[i] % speed != 0) {
                h++;
            }
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        long long result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long  hours = fun(piles,mid); // mid in this mean speed in that function // take it as long long 
            if (hours > h) {
                low = mid + 1; // search in right
            } else {
                result = mid;
                high = mid - 1;
            }
        }
        return result;
    }
};