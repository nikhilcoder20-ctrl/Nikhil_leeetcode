class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != maxi) {
                count = count + (maxi - nums[j]);
            }
        }
        return count;
    }
};