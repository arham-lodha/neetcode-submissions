class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int res = 0;
        int count = 1;
        int i = 0;
        int j = i + 1;
        unordered_map<char, int> char_to_index;
        char_to_index[s[i]] = i;
        while(i < s.size() && j < s.size()){
            if(char_to_index.contains(s[j])){
                res = max(res, count);
                i = char_to_index[s[j]] + 1;
                char_to_index.clear();
                char_to_index[s[i]] = i;
                j = i + 1;
                count = 1;
            }
            else{
                char_to_index[s[j]] = j;
                count++;
                j += 1;
            }
        }

        return max(res, count);
    }
};
