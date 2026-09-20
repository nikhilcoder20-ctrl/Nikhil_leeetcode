class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0;
        int countR = 0;
        int countBlank = 0;
        
        // Count the occurrences of each move
        for (char c : moves) {
            if (c == 'L') {
                countL++;
            } else if (c == 'R') {
                countR++;
            } else {
                countBlank++;
            }
        }
        
        
        return abs(countL - countR) + countBlank;
    }
};
