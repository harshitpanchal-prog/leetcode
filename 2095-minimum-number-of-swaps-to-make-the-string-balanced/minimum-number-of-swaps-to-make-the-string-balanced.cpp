class Solution {
public:
    int minSwaps(string s) {
        float size=0;
        for(char &ch:s){
            if(ch == '['){
                size++;
            }else if(size>0){
                size--;
            }
        }
        
        return ceil(size/2.0);
    }
};