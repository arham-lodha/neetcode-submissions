class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> frequencies;

        for (string &str : strs) {
            vector<int> number(26, 0);

            for (int j = 0; j < str.length(); j++) {
                number[str[j] - 'a']++;
            }
            
            string key = "";
            for(int c: number){
                key += to_string(c) + "#";
            }

            frequencies[key].push_back(str);
        }

        for(auto &pair: frequencies){
            result.push_back(pair.second);
        }

        return result;
    }
};
