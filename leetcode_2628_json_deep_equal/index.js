function helper(key, val){
    if (val && typeof val === "object" && !Array.isArray(val)){
        return Object.fromEntries(Object.entries(val).sort());
    } else {
        return val;
    }
}

/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    return JSON.stringify(o1, helper) === JSON.stringify(o2, helper);
};
