/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
        return x => functions
            .reverse()
            .reduce((ac, item) => item(ac), x)
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
