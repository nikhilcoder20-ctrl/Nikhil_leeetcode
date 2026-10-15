#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long ans = 0;

        for (int i = 0; i < n; i++) {
            // 1. Changed j = i + 1 to j = i to include single-element subarrays
            for (int j = i; j < n; j++) {
                
                // 3. Moved the set outside the k loop so it doesn't reset on every single element
                unordered_set<int> result;
                
                // 2. Changed k < n to k <= j to look only inside the subarray nums[i...j]
                for (int k = i; k <= j; k++) {
                    result.insert(nums[k]);
                }
                
                long result_count = result.size();
                ans = ans + (result_count * result_count);
            }
        }
        return ans;
    }
};
