//2634. Filter Elements from Array
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filteredArr=[];

    for(let i=0;i<arr.length;i++){
        if(Boolean(fn(arr[i],i)))   filteredArr=[...filteredArr,arr[i]];
    }

    return filteredArr
    
};