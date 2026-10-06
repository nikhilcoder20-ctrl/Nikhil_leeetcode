class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int count1=0;
        int count2=0;

       for(char c : s){
            if(c =='('){
                count2++;

            }
            else if(count2>0){
                count2--;
            }
            else {
                count1++;
            }
            

        }
        return count1+count2;
    }
};