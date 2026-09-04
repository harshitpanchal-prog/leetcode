class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int num = low ; num<=high ; num++){
            string s = to_string(num);
            int len=s.length();
            if(len%2 !=0){
                continue;
            }
            int leftsum=0;
            int rightsum=0;
             
            for(int i=0 ; i<len/2 ; i++){
                leftsum+=s[i]-'0';
            } 
            for(int i=len/2 ; i<len ;i++){
                rightsum+=s[i]-'0';
            }
            if(leftsum == rightsum){
                count++;
            }
            
        }
        return count;
    }
};