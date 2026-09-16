class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxi = 0; 
        
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (colors[i] == colors[j]) {
                j--; 
            } else {
                maxi = max(maxi, j - i);
                break; 
            }
        }
        

        i = 0;
        j = n - 1;
        while (i < j) {
            if (colors[i] == colors[j]) {
                i++;
            } else {
                maxi = max(maxi, j - i);
                break;
            }
        }
        
        return maxi;
    }
};
