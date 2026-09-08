class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(char ch:s){
            if(ch>='A' && ch<='Z'){
                ch=ch+32;
                str+=ch;

            }
            else if((ch>='a' && ch<='z')|| (ch>='0' && ch<='9')){
                str+=ch;

            }
            else continue;

        }
        int n=str.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;

        }
        return true;



        
    }
};