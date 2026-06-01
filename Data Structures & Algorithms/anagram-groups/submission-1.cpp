class Solution {
   public:
    bool isAnagram(const vector<int> &number_a, const vector<int> &number_b) {
        if(number_a.size() != number_b.size()) return false;
        for (int i = 0; i < number_a.size(); i++) {
            if (number_a[i] != number_b[i]) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<vector<int>> number_arrays;
        vector<bool> taken(strs.size(), false);

        for (string &str : strs) {
            vector<int> number(26);

            for (int j = 0; j < str.length(); j++) {
                number[static_cast<int>(str[j]) - 97]++;
            }

            number_arrays.push_back(number);
        }

        for (int i = 0; i < strs.size(); i++) {
            if (!taken[i]) {
                vector<string> new_class;
                new_class.push_back(strs[i]);
                taken[i] = true;

                for (int j = i + 1; j < strs.size(); j++) {
                    if (strs[i].length() == strs[j].length() && !taken[j] &&
                        isAnagram(number_arrays[i], number_arrays[j])) {
                            new_class.push_back(strs[j]);
                            taken[j] = true;
                    }
                }

                result.push_back(new_class);
            }
        }

        return result;
    }
};
