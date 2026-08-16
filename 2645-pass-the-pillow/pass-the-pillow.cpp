class Solution {
public:
    int passThePillow(int n, int time) {
        int fullRound = time/(n-1);
        int timeleft = time%(n-1);
        
        if(fullRound % 2 == 0 ){
            return (timeleft+1);
        }else{
            return (n-timeleft);
        }
        return -1;
    }
};