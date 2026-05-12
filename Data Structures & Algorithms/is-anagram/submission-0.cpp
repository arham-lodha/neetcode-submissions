class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        std::unordered_map<char, int> charFreq;

        for(char c: s){
            if(charFreq.contains(c)){
                charFreq[c] = charFreq[c] + 1;
            }
            else{
                charFreq[c] = 1;
            }
        }

        for(char c: t){
            if(charFreq.contains(c)){
                charFreq[c] = charFreq[c] - 1;

                if(charFreq[c] == 0){
                    charFreq.erase(c);
                }
            }
            else{
                return false;
            }
        }

        return true;

    }
};
