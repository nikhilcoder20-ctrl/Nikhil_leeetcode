class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       
        vector<int> minFreq(26, 0);
        for (char c : words[0]) {
            minFreq[c - 'a']++;
        }
        
       
        for (int i = 1; i < words.size(); i++) {
            vector<int> currentFreq(26, 0);
            for (char c : words[i]) {
                currentFreq[c - 'a']++;
            }
            
            
            for (int k = 0; k < 26; k++) {
                minFreq[k] = min(minFreq[k], currentFreq[k]);
            }
        }
        
      
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (minFreq[i] > 0) {
                result.push_back(string(1, 'a' + i));
                minFreq[i]--;
            }
        }
        
        return result; 
    }
};
