class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for(int i = 0; i < nums.size(); i++) {
            int num = target-nums[i];
            if(umap.find(num) != umap.end()) return { umap[num], i };
            umap[nums[i]] = i;
        }
        return {-1,-1};
    }
};
