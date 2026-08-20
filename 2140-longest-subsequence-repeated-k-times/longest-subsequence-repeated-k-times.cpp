class Solution {
public:
    string result = "";

bool issubsequence(string& s, string& sub, int k) {
    int i = 0;
    int j = 0;

    int L = sub.length();
    int n = s.length();

    while(i < n && j < k * L) {
        if(s[i] == sub[j % L]) {
            j++;
        }
        i++;
    }

    return j == k * L;
}

void backtrack(string& s, string& curr,
               vector<bool>& canUse,
               vector<int>& requiredfreq,
               int k, int maxLen) {

    if(curr.length() > maxLen) {
        return;
    }

    if((curr.length() > result.length() ||
        (curr.length() == result.length() && curr > result))
        && issubsequence(s, curr, k)) {

        result = curr;
    }

    for(int i = 0; i < 26; i++) {

        if(!canUse[i] || requiredfreq[i] == 0) {
            continue;
        }

        char ch = i + 'a';

        curr.push_back(ch);
        requiredfreq[i]--;

        backtrack(s, curr, canUse, requiredfreq, k, maxLen);

        curr.pop_back();
        requiredfreq[i]++;
    }
}

string longestSubsequenceRepeatedK(string s, int k) {

    result.clear();

    int n = s.length();

    vector<int> freq(26, 0);

    for(char& ch : s) {
        freq[ch - 'a']++;
    }

    vector<bool> canUse(26, false);
    vector<int> requiredfreq(26, 0);

    for(int i = 0; i < 26; i++) {
        if(freq[i] >= k) {
            canUse[i] = true;
            requiredfreq[i] = freq[i] / k;
        }
    }

    int maxLen = n / k;

    string curr = "";

    backtrack(s, curr, canUse, requiredfreq, k, maxLen);

    return result;
}
};