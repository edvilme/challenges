/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let n = 0;
    let m = 1;
    while(true){
        yield n;
        let int = n + m;
        n = m;
        m = int;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
