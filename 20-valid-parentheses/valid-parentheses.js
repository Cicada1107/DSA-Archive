/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const n = s.length;
    let stack = [];

    const hash = {
        '}': '{',
        ']': '[',
        ')': '('
    }

    for(let i=0; i<n; i++){
        const char = s[i];

        if(hash[char]){
            const top = stack.length === 0 ? '#' : stack.pop();
            if(top !== hash[char]) return false;
        }
        else{
            stack.push(char);
        }
    }

    if(stack.length === 0) return true;

    return false;
};