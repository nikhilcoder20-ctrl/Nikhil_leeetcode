#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution { 
public: 
    int getDigitsum(int num) { 
        int sum = 0; 
        while (num > 0) { 
            sum = sum + (num % 10); 
            num = num / 10; 
        } 
        return sum; 
    } 

    int minSwaps(vector<int>& nums) { 
        int n = nums.size(); 
        vector<int> aftersort(nums); 

        auto lambda = [&](int num1, int num2) { 
            int num1digitssum = getDigitsum(num1); 
            int num2digitssum = getDigitsum(num2); 
            if (num1digitssum != num2digitssum) { 
                return num1digitssum < num2digitssum; 
            } 
            return num1 < num2; 
        }; // Fixed: Added missing semicolon after lambda

        sort(begin(aftersort), end(aftersort), lambda); // Fixed: Removed dot from 'end.(aftersort)'

        // Note: This logic assumes all elements in 'nums' are unique. 
        // If there are duplicate elements, an unordered_map approach needs modification.
        unordered_map<int, int> valind; 
        for (int i = 0; i < n; i++) { 
            valind[nums[i]] = i; 
        } 

        int swapcount = 0; // Fixed: Removed the duplicate 'int swapcount = 0' from the top
        for (int i = 0; i < n; i++) { 
            int expectedval = aftersort[i]; // Fixed: Changed 'aftersorted' to 'aftersort'
            int curval = nums[i]; 

            if (expectedval == curval) 
                continue; // Fixed: Changed typo 'countine' to 'continue'

            int idx = valind[expectedval]; 
            
            // Perform the swap in the array
            nums[i] = expectedval; 
            nums[idx] = curval; 

            // Update the index mappings
            valind[expectedval] = i; 
            valind[curval] = idx; 
            swapcount++; 
        } 
        return swapcount; 
    } 
};
