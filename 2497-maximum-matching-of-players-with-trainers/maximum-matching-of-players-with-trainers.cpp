class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        int n=players.size();
        int count=0;
        int m=trainers.size();
        int i=0;
        int j=0;

        while(i<n && j<m){
            if(players[i]>trainers[j]){
                j++;
            }else{
                count++;
                i++;
                j++;
            }
        }
        return count;
        
    }
};