class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */

    sortString(str) {
        let arr = str.split('');
        arr.sort();
        const sortedStr = arr.join('');
        return sortedStr;
    }
    groupAnagrams(strs) {
        let word_map = new Map();
        for(let str of strs) {
            let key = this.sortString(str);
            if(!word_map.get(key)) {
                word_map.set(key,[]);
            }
            let words = word_map.get(key);
            words.push(str);
            word_map.set(key,words);
        }
        const results = [];
        for(let [k,v] of word_map) {
            results.push(v);
        }
        return results;
    }
}
