class Solution {
public:
    bool isAnagram(string s, string t) {
        char smap[26] = {0};
        for(char ch : s) smap[ch-'a']++;
        for(char ch : t) smap[ch-'a']--;
        for(int i = 0; i < 26; i++) if(smap[i] != 0) return false;
        return true;
    }
};
