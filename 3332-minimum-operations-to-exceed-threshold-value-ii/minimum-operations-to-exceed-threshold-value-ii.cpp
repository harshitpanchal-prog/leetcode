class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<>>pq;
        for(int &num:nums){
            pq.push(num);
        }
        int count = 0;
        while(pq.top() < k ){
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            pq.push(min(num1,num2)*2 + max(num1,num2));
            count++;
        }
        return count;

    }
};