class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int maxunsatcust=0;
        int currunsat=0;
        for(int i=0; i <minutes ; i++){
            currunsat+=customers[i]*grumpy[i];
        }
        maxunsatcust=currunsat;
        int i=0;
        int j=minutes;
        while(j<n){
            currunsat+=customers[j]*grumpy[j];
            currunsat-=customers[i]*grumpy[i];
            maxunsatcust=max(maxunsatcust,currunsat);
            i++;
            j++;
        }
        int totalsat=maxunsatcust;
        for(int i=0; i<n ; i++){
            totalsat+=customers[i]*(1-grumpy[i]);
        }
        return totalsat;

    }
};