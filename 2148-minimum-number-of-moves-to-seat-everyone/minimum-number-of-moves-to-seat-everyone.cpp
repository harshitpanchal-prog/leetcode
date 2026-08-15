class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> pos_seat(101,0);
        vector<int> pos_student(101,0);
        int n=seats.size();
        for(int  &pos:seats){
            pos_seat[pos]++;
        }
    
        for(int  &pos:students){
            pos_student[pos]++;
        }

        int i=0;
        int j=0;
        int result=0;
        while(i<=100 && j<=100){
            if(pos_seat[i]==0){
                i++;
            }
            if(pos_student[j]==0){
                j++;
            }
            if(i<=100 && j<=100 && pos_seat[i]!=0 && pos_student[j]!=0){
                result+=abs(i-j);
                pos_seat[i]--;
                pos_student[j]--;
                
                
            }
        }
        return result;
    }
};