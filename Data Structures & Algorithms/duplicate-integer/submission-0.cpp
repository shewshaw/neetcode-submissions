class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int num : nums) {
            umap[num]++;
            if(umap[num] > 1) return true;
        }
        return false;
    }
};