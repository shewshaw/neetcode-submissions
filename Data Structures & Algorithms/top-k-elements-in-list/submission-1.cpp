class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> u_map;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for(int num : nums) {
            u_map[num]++;
        }
        auto itr = u_map.begin();
        while(itr != u_map.end()) {
            pq.push({ itr->second,itr->first });
            if(pq.size() > k) pq.pop();
            itr++;
        }
        vector<int> result;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            result.push_back(top.second);
        }
        return result;
    }
};
