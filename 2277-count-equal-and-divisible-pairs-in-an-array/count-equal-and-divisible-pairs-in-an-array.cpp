class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        long long result=0;
        unordered_map<int ,vector<int>>indices_map;
        for(int i=0 ; i<n ; i++){
            indices_map[nums[i]].push_back(i);
        }

        unordered_set<int>div;
        for(int f=1 ; f*f<=k ; f++){
            if(k%f == 0 ){
                div.insert(f);
                div.insert(k/f);
            }
        }
        for(auto&[num,indices] : indices_map){
            unordered_map<int,int>factors_map;
            for(int i : indices){
                int GCD = gcd(i,k);
                int j = k/GCD;
                result+=factors_map[j];
                for(int f : div){
                    if(i%f ==0 ){
                        factors_map[f]++;
                    }
                }
            }
        }
        return result;

    }
};