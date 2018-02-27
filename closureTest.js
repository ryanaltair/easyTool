// why we need closure?

function noMakeClosure() {
    var counter = 1;
    counter++;
    return counter;
}

function makeClosureOutside() {
    var counterOut = 1;
    counterOut++;
    return function () {
        var closureCounter = 1;
        return counterOut;
    };
}

function makeClosureInside() {
    var counterOut = 1;
    counterOut++;
    return function () {
        var closureCounter = 1;
        return closureCounter;
    };
}

var test1noClosure = noMakeClosure();
var test2noClosure = noMakeClosure();

var test1useClosureOut = makeClosureOutside();
var test2useClosureOut = makeClosureOutside();

var test1useClosureIn = makeClosureInside();
var test2useClosureIn = makeClosureInside();

console.log("test1 no Closure: " + test1noClosure);
console.log("test2 no Closure: " + test2noClosure);

console.log("test1 use ClosureOut: " + test1useClosureOut());
console.log("test2 use ClosureOut: " + test2useClosureOut());

console.log("test1 use ClosureIn: " + test1useClosureIn());
console.log("test2 use ClosureIn: " + test2useClosureIn());