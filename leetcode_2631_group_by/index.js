/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    const dict = {};
    for (let item of this){
        const key = fn(item);
        if (dict[key] == undefined)
            dict[key] = [item];
        else
            dict[key].push(item);
    }
    return dict;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
