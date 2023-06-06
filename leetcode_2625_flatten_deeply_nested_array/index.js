/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    // Store results here
    const results = [];
    // Iterate over elements
    for (let item of arr){
        // If is array
        if (Array.isArray(item) && n > 0) 
            results.push(...flat(item, n-1));
        else 
            results.push(item);
    }
    return results;
};
