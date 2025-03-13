//https://leetcode.com/problems/function-composition/
//2629. Function Composition
/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    const p = functions;

    return function(x) {
        for(let i=p.length -1;i>=0;i--){
            let s=p[i];
            x = s(x);
        }   
        return x; 
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */