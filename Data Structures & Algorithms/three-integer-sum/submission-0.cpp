class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0; i < n-1; i++) {
            int target = -nums[i];
            int l = i+1;
            int r = n-1;
            while(l < r) {
                if(nums[l] + nums[r] == target) {
                    result.push_back({ nums[i], nums[l], nums[r] });
                    while(l < n-1 && nums[l] == nums[l+1]) l++;
                    while(r > l+1 && nums[r] == nums[r-1]) r--;
                }
                if(nums[l] + nums[r] > target) r--;
                else l++;
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++;

        }
        return result; 
    }
};
