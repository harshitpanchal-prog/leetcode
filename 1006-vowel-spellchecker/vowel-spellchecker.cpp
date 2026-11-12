class Solution {
public:
    unordered_set<string>exact_set;
    unordered_map<string,string>case_map;
    unordered_map<string,string>vowel_map;
    string to_lower(string s){
        string result=s;
        for(char&ch:result){
            ch=tolower(ch);
        }
        return result;
    }
    string replaceVowel(string&s){
        string result =s;
        for(char & ch :result){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                ch='*';
            }
        }
        return result;
    }
    string checkForMatch(string &query){
        if(exact_set.count(query)){
            return query;
        }
        string lowercase=to_lower(query);
        if(case_map.count(lowercase)){
            return case_map[lowercase];
        }
        string vowelCase=replaceVowel(lowercase);
        if(vowel_map.count(vowelCase)){
            return vowel_map[vowelCase];
        }
        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exact_set.clear();
        case_map.clear();
        vowel_map.clear();
        for(string word:wordlist){
            exact_set.insert(word);
            string lowercase=to_lower(word);
            if(case_map.find(lowercase) == case_map.end()){
                case_map[lowercase]=word;
            }
            string vowelcase=replaceVowel(lowercase);
            if(vowel_map.find(vowelcase)==vowel_map.end()){
                vowel_map[vowelcase]=word;
            }

        }
        vector<string>result;
        for(string &query:queries){
            result.push_back(checkForMatch(query));
        }
        return result;
    }
};