class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int s = prices.size();
        vector<int> min_left(s, 100);
        vector<int> max_right(s);

        min_left[0] = prices[0];
        max_right[s - 1] = prices[s - 1];
        for(int i = 1; i < s; i++){
            min_left[i] = min(min_left[i - 1], prices[i]);
            max_right[s - i - 1] = max(max_right[s - i], prices[s - i - 1]);
        }

        int max_prof = 0;

        for(int i = 0; i < s; i++){
            max_prof = max(max_prof, max_right[i] - min_left[i]);
        }

        return max_prof;
    }
};