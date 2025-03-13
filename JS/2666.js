//https://leetcode.com/problems/allow-one-function-call/?envType=study-plan-v2&envId=30-days-of-javascript
//2666. Allow One Function Call
/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let calls=0;
    let p=fn;
    
    return function(...args){
        if(calls===0){
            calls+=1;
            return fn(...args);
        } 
        else return;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
