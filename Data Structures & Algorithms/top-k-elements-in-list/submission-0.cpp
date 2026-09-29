class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> u_map;
        priority_queue<pair<int,int>> pq;

        for(int num : nums) {
            u_map[num]++;
        }
        auto itr = u_map.begin();
        while(itr != u_map.end()) {
            pq.push({ itr->second,itr->first });
            itr++;
        }
        vector<int> result;
        int count = 0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            count++;
            result.push_back(top.second);
            if(count == k) break;
        }
        return result;
    }
};
