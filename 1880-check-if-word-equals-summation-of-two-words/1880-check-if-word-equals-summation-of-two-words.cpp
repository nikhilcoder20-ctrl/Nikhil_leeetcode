class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int n1=firstWord.size();
        int n2=secondWord.size();
        int n3=targetWord.size();
        int sum1=0;
        int sum3=0;
        int sum2=0;
        for(int i=0;i<n1;i++){
         sum1=sum1*10+ firstWord[i]-'a';

            
        }
        for(int i=0;i<n2;i++){
         sum2=sum2*10+ secondWord[i]-'a';

            
        }
        for(int i=0;i<n3;i++){
         sum3=sum3*10+ targetWord[i]-'a';

            
        }
        if(sum1+sum2==sum3){
            return true;
        }
    
        return false;
        
    }
};