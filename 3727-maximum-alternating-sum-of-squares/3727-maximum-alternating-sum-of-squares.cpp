class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n - 1;

        int minus_slots = n / 2;

        while (i <= j) {
            if (i < minus_slots) {

                sum -= nums[i];
                i++;
            } else {

                sum += nums[j];
                j--;
            }
        }

        return sum;
    }
};
