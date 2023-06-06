// The easiest way to set up the problem is to show a sample invocation.
// sayIt("Hello")("my")("name")("is")("Brian")(); // "Hello my name is Brian"
// Each successive call should continue to build up the final string. A final call without any arguments should return the built up string.

let accumStr;
function sayIt(str){
    // If str is undefined
    if (str == undefined){
        let temp = accumStr;
        accumStr = undefined;
        return temp;
    }
    // For the first time
    if (accumStr == undefined)
        accumStr = str;
    return function(nextStr){
        if (nextStr != undefined)
            accumStr += " " + nextStr;
            return sayIt(nextStr);
    }
}

console.log(sayIt("Hello")("my")("name")("is")("Biran")());
console.log(sayIt("Hello2")("my2")("name2")("is2")());

// OTHER SOLUTIONS

/*
// uses .bind for partial application
var sayIt = acc.bind(null, '');
function acc(sofar, str) {
  if (!str) return sofar;
  return acc.bind(null, sofar + (sofar ? ' ' : '') + str);
}


function sayIt(seed) {
  var parts = [seed];
  return function append(str) {
    if (str) {
      parts.push(str);
      return append;
    } else {
      return parts.join(" ");
    }
  }
}*/