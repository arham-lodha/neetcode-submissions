class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); i++){
            if(seen.contains(target - nums[i])){
                return {seen[target - nums[i]], i};
            }

            seen.insert({nums[i], i});
        }

        return {-2, -1};
        
    }
};
