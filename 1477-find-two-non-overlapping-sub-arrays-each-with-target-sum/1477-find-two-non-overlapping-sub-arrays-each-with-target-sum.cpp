class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // min_len[i] will store the minimum length of a valid subarray found so far up to index i
        vector<int> min_len(n, INT_MAX);
        
        int window_sum = 0;
        int left = 0;
        int min_total_sum = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            window_sum += arr[right];
            
            // Shrink the window from the left if the sum exceeds target
            while (window_sum > target && left <= right) {
                window_sum -= arr[left];
                left++;
            }
            
            // If we found a valid subarray summing up to target
            if (window_sum == target) {
                int current_len = right - left + 1;
                
                // If there is a valid non-overlapping subarray before the current 'left' index
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    min_total_sum = min(min_total_sum, current_len + min_len[left - 1]);
                }
                
                // Update the minimum length found at or before the current right index
                if (right == 0) {
                    min_len[right] = current_len;
                } else {
                    min_len[right] = min(min_len[right - 1], current_len);
                }
            } else {
                // If no matching subarray ends at 'right', carry forward the best length from 'right - 1'
                if (right > 0) {
                    min_len[right] = min_len[right - 1];
                }
            }
        }
        
        // Return -1 if two non-overlapping subarrays couldn't be formed
        return (min_total_sum == INT_MAX) ? -1 : min_total_sum;
    }
};
