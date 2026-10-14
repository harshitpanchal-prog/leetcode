class Solution {
public:
    vector<int>getvectorcount(int n){
        vector<int>vec(10,0);
        while(n){
            vec[n%10]++;
            n/=10;
        }
        return vec;
    }
    bool reorderedPowerOf2(int n) {
        vector<int>input=getvectorcount(n);
        for(int i=0 ; i<=29 ; i++){
            if(input == getvectorcount(1<<i)){
                return true;
            }
        }
        return false;
    }
};