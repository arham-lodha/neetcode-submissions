class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> before(nums.size(), 1);
        vector<int> after(nums.size(), 1);

        
        for(int i = 1; i < nums.size(); i++){
            before[i] = before[i - 1] * nums[i - 1];
            after[nums.size() - i - 1] = after[nums.size() - i] * nums[nums.size() - i];
        }

        for(int i = 0; i < nums.size(); i++){
            before[i] *= after[i];
        }

        

        return before;
    }
};
