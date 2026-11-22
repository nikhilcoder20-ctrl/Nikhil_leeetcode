class Solution {
public:
    bool checkString(string s) {
        for (int i = 0; i < s.size(); i++) {
            if(s.find ("ba") != string::npos){
            return false;
        }
        }

        return true;
    }
};