/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const n = strs.length;
    let hash = new Map();

    for(let i=0; i<n; i++){
        const sortedStr = strs[i].split('').sort().join('');

        if(!hash.has(sortedStr)){
            hash.set(sortedStr, []);
        }

        hash.get(sortedStr).push(strs[i]);
    }

    return Array.from(hash.values());
};