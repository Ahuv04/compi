//2665. Counter II
/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let p=init;
    const q=init;
    return {
        increment: () =>{
            p+=1;
            return p;
        },
        decrement: ()=>{
            p-=1;
            return p;
        },
        reset: ()=>{
            p=q;
            return p;
        }
    }
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */