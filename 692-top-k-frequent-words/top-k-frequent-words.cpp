class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(string &word : words){
            mp[word]++;
        }

        vector<pair<string,int>>vec;
        for(auto &it : mp){
            vec.push_back({it.first,it.second});
        }
        auto lambda=[](pair<string,int>P1,pair<string,int>P2){
            if(P1.second == P2.second){
                return P1.first<P2.first;
            }
            return P1.second>P2.second;
        };

        sort(vec.begin(),vec.end(),lambda);
        
        int i=0;
        vector<string>result;
        while(i<k){
            result.push_back(vec[i].first);
            i++;
        }
        return result;
    }
};