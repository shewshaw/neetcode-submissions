class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans  = 0;
        int l = 0;
        int r = heights.size() - 1;
        while(l < r) {
            ans  = max((r-l)*min(heights[l],heights[r]), ans);
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
