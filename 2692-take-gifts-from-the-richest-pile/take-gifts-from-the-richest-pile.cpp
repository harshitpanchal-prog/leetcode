class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        for(int& gift:gifts){
            sum+=gift;
        }
        priority_queue<int>pq(begin(gifts),end(gifts));
        long long mysum=0;
        while(k--){
            int maxel = pq.top();
            pq.pop();
            int remaining = sqrt(maxel);
            mysum+=maxel-remaining;
            pq.push(remaining);

        }
        return sum - mysum;
    }
};