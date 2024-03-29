/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    async function next(){
        if (functions.length == 0) return;
        await functions.shift()();
        await next();
    }
    await Promise.all(
        Array(n).fill().map(next)
    );
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */
