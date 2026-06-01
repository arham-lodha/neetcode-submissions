class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> counts(2000, 0);

        for(int i: nums){
            counts[i + 1000]++;
        }

        vector<pair<int, int>> simplified_counts;
        for(int i = 0; i < counts.size(); i++){
            if(counts[i] != 0){
                simplified_counts.emplace_back(i, counts[i]);
            }
        }

        vector<int> results;

        sort(simplified_counts.begin(), simplified_counts.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.second > b.second;
        });

        for(int i = 0 ; i < k; i++){
            results.push_back(simplified_counts[i].first - 1000);
        }

        return results;
    }
};
