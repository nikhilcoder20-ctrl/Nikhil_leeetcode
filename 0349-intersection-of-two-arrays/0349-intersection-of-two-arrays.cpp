class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // 1. Sort both vectors (correct)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int p1 = 0;
        int p2 = 0;
        set<int> ans; 
        
        
        while(p1 < n1 && p2 < n2) {
            if(nums1[p1] == nums2[p2]) {
                ans.insert(nums1[p1]); 
                p1++;                  
                p2++;
            }
            else if (nums1[p1] < nums2[p2]) {
                p1++;
            }
            else {
                p2++;
            }
        }
        
       
        return vector<int>(ans.begin(), ans.end());
    }
};
