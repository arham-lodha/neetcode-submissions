class Solution {
   public:
    int trap(vector<int>& height) {
        int s = height.size();
        vector<int> max_left(s);
        vector<int> max_right(s);

        for(int i = 1; i < s; i++){
            max_left[i] = max(max_left[i - 1], height[i - 1]);
            max_right[s - i - 1] = max(max_right[s - i], height[s-i]);
        }

        int water = 0;

        for(int i = 0; i < s; i++){
            water += max(0, min(max_left[i], max_right[i]) - height[i]);
        }


        return water;
    }
};
