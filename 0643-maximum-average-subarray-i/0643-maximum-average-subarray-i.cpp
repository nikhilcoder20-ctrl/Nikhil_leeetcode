class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        
        // Step 1: Calculate the sum of the very first window (first k elements)
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        // Initialize our tracking variable with the first window's average
        double max_avg = sum / k; 

        // Step 2: Slide the window across the rest of the array
        // 'i' represents the incoming element on the right side of the window
        for (int i = k; i < n; i++) {
            // Add the new element entering from the right (nums[i])
            // Subtract the old element leaving from the left (nums[i - k])
            sum = sum + nums[i] - nums[i - k];
            
            double result = sum / k;
            max_avg = max(max_avg, result);
        }
   
        return max_avg;
    }
};
