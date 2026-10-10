class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n){
            return nums;
        }
        vector<int>temp(nums);
        nth_element(begin(temp),begin(temp)+k-1,end(temp),greater<int>());
        int kthlargest=temp[k-1];
        int countkthlargest=count(begin(temp),begin(temp)+k,kthlargest);
        vector<int>result;
        for(int &num : nums){
            if(num>kthlargest){
                result.push_back(num);
            }else if(num==kthlargest && countkthlargest>0){
                result.push_back(num);
                countkthlargest--;
            }
            if(result.size()==k){
                break;
            }
        }
        return result;
    }
};