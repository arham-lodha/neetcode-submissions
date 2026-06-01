class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
            result = max(result, min(heights[l], heights[r]) * (r - l));

            if(heights[l] < heights[r]) l++;
            else r--;
        }


        return result;
    }
};
