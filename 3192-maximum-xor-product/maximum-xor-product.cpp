class Solution {
public:
    int M=1e9+7;
    typedef long long ll;
        
    int maximumXorProduct(long long a, long long b, int n) {
        ll xXora=0;
        ll xXorb=0;
        for(long long i=49 ; i>=n ; i--){
            bool a_it_bit=((a>>i)&1)>0;
            bool b_it_bit=((b>>i)&1)>0;
            if(a_it_bit==true){
                xXora=(xXora^(1ll <<i));
            }
            if(b_it_bit==true){
                xXorb=(xXorb^(1ll <<i));
            }
        }
        for(ll i=n-1 ; i>=0 ; i--){
            bool a_ith_bit=(a&(1ll << i))>0;
            bool b_ith_bit=(b&(1ll << i))>0;
            if(a_ith_bit == b_ith_bit){
                xXora=(xXora^(1ll << i));
                xXorb=(xXorb^(1ll << i));
                continue;
            }
            if(xXora > xXorb){
                xXorb=(xXorb^(1ll << i));
            }else{
                xXora=(xXora^(1ll << i));
            }

        }
        xXora = (xXora%M);
        xXorb = (xXorb%M);
        return (xXora *xXorb)%M;
    }
};