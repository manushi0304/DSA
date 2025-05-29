class Solution {
public:
 bool canShip(vector<int>& weights, int days, int capacity) {
        int dayCount = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                dayCount++;        // need a new day
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return dayCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
     int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid)) {
                result = mid;       // try to minimize
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;   
    }
};