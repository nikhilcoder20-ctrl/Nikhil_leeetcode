class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            long long product = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long val = nums[j];
                product = product * val;
                g = (g == 0) ? val : std::gcd(g, val);
                l = std::lcm(l, val);

                if (product == l * g) {
                    ans = max(ans, static_cast<long long>(j - i + 1));
                }

                
                if (product > 2520LL * l * g) {
                    break;
                }
            }
        }

        return static_cast<int>(ans);
    }
};