class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int >st;
        for(int& num:nums){
            if(st.count(num)){
                st.erase(num);
            }else{
                st.insert(num);
            }
        }
        
        return st.empty();
    }
};