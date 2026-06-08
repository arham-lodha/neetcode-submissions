class Solution {
public:
    string convertFreq(const int (&freq)[26]){
        string result = "";
        
        for(int i = 0 ; i < 26; i++){
            if(freq[i] > 0){
                result += (char)(i + 'a');
                result += std::to_string(freq[i]);
                result += "; ";
            }
        }
        return result;
    }
    
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        if (l2 < l1) return false;
        int s1freq[26] = {0};

        for(int i = 0; i < l1; i++){
            s1freq[s1[i] - 'a']++;
        }

        string freq_string_s1 = convertFreq(s1freq);

        int freq[26] = {0};
        int l = 0;
        int r = 0;
        
        while(r < l2){
            freq[s2[r] - 'a']++;

            if(r - l == l1 - 1){
                string freq_s2 = convertFreq(freq);
                if(freq_s2 == freq_string_s1) return true;

                freq[s2[l] - 'a']--;
                l++;
            }

            r++;
        }

        
        return false;
    }
};
