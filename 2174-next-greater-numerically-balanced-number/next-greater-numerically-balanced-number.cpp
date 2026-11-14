class Solution {
public:
    vector<int>digit_count{0,1,2,3,4,5,6,7,8,9};

    int backTrack(int n,int curr,int count){
        if(count==0){
            for(int digit=1;digit<=9;digit++){
                if(digit_count[digit] != 0 && digit_count[digit] != digit){
                    return 0;
                }
            }
            return curr>n?curr:0;
        }
        int result=0;
        for(int digit=1 ; digit<=9 ; digit++){
            if(digit_count[digit]>0 && digit_count[digit]<=count){
                digit_count[digit]--;
                result = backTrack(n,curr*10+digit,count-1);
                digit_count[digit]++;
            }
            if(result!=0){
                break;
            }
        }
        return result;
    }

    int nextBeautifulNumber(int n) {
        int numDigits=to_string(n).length();
        int result=backTrack(n,0,numDigits);
        if(result == 0){
            result=backTrack(n,0,numDigits+1);
        }
        return result;
    }
};