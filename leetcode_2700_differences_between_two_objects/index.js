/**
 * @param {object} obj1
 * @param {object} obj2
 * @return {object}
 */
function objDiff(obj1, obj2) {
    // Compare
    // If no difference
    if (obj1 === obj2)
        return {};
    // If items are not objects
    if (typeof obj1 !== 'object' || typeof obj2 !== 'object') 
        return [obj1, obj2];
    // If items are arrays
    if (Array.isArray(obj1) !== Array.isArray(obj2)) 
        return [obj1, obj2];
    const returnObject = {};
    for (const key in obj1) {
        if (key in obj2) {
            const subDiff = objDiff(obj1[key], obj2[key]);
            if (Object.keys(subDiff).length > 0) {
                returnObject[key] = subDiff;
            }
        }
    }
    return returnObject;
};/**
 * @param {object} obj1
 * @param {object} obj2
 * @return {object}
 */
function objDiff(obj1, obj2) {
    // Compare
    // If no difference
    if (obj1 === obj2)
        return {};
    // If items are not objects
    if (typeof obj1 !== 'object' || typeof obj2 !== 'object') 
        return [obj1, obj2];
    // If items are arrays
    if (Array.isArray(obj1) !== Array.isArray(obj2)) 
        return [obj1, obj2];
    const returnObject = {};
    for (const key in obj1) {
        if (key in obj2) {
            const subDiff = objDiff(obj1[key], obj2[key]);
            if (Object.keys(subDiff).length > 0) {
                returnObject[key] = subDiff;
            }
        }
    }
    return returnObject;
};
