class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == 0) return 0;
        int max_window = 1;
        int max_freq = 1;
        int freq[26] = {0};
        freq[s[0] - 'A']++;
        int l = 0;
        int r = 1;
        
        while(r < s.size()){
            int window_size = r - l + 1;
            freq[s[r] - 'A']++;
            max_freq = max(max_freq, freq[s[r] - 'A']);
    
            if(window_size - max_freq > k){
                freq[s[l] - 'A']--;
                l++;
            }
            else{
                max_window = max(window_size, max_window);
            }

            r++;
        }

        return max_window;
    }
};
