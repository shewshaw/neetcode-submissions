class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto str : strs) {
            encoded += to_string(str.size());
            encoded += '#';
            encoded += str;      
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int idx = 0;

        while (idx < s.size()) {
            int len = 0;
            while (s[idx] != '#') {
                len = len * 10 + (s[idx] - '0');
                idx++;
            }
            idx++;

            string str = "";
            for (int i = 0; i < len; i++) {
                str += s[idx++];
            }

            ans.push_back(str);
        }
        return ans;
    }
};
