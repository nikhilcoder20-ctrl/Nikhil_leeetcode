class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for (int i = 1; i <= n; i++) {
            int nums = i;
            if (nums % 3 == 0 && nums % 5 == 0) {
                answer.push_back("FizzBuzz");

            } else if (nums % 3 == 0) {
                answer.push_back("Fizz");

            } else if (nums % 5 == 0) {
                answer.push_back("Buzz");

            } else {
                answer.push_back(to_string(i));
            }
        }
        return answer;
        
    }
};