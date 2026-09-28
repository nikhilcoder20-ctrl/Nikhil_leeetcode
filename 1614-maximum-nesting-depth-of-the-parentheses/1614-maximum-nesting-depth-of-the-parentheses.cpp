class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int maxi = 0;

        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ans++;
                maxi = max(ans,maxi);

            }

            else if (s[i] == ')') {
                ans--;
            }
        }

        maxi = max(maxi, ans);
        return maxi;
    }
};