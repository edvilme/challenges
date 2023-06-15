/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    this.toBe = otherVal => {
        if(otherVal === val) return true;
        else throw "Not Equal";
    }
    this.notToBe = otherVal => {
        if(otherVal !== val) return true;
        else throw "Equal";
    }
    return this
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
