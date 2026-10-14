class Solution {
public:
    string Rordered(int n){
        string s=to_string(n);
        sort(begin(s),end(s));
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string a=Rordered(n);
        for(int p=0 ; p<=29 ; p++){
            if(a==Rordered(1<<p)){
                return true;
            }
        }
        return false;
    }
};