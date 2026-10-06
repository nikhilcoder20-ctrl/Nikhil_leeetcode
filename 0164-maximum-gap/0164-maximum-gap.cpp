class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int ans = 0;
        if (n == 0 || n == 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-1; i++) {
            maxi = nums[i + 1] - nums[i];
            ans = max(maxi, ans);
        }
        return ans;
    }
};