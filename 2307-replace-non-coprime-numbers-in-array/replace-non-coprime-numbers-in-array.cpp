class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for(int & num : nums){
            while(!result.empty()){
                int prev=result.back();
                int curr=num;
                int GCD=gcd(curr,prev);
                if(GCD==1){
                    break;
                }
                result.pop_back();
                int LCM=curr/GCD*prev;
                num = LCM;
            }
            result.push_back(num);
        }
        return result;
    }
};