import core from "./lib/addon.cjs"

const DoubleTensor = new core.DoubleTensor();
const FloatTensor = new core.FloatTensor();
const HalfTensor = new core.HalfTensor();

function testIsTensor(obj) {
    if (core.isTensor(obj)) {
      console.log('The object is a tensor.');
    } else {
      console.log('The object is NOT a tensor.');
    }
}

testIsTensor(DoubleTensor); // Output: The object is a tensor.
testIsTensor(FloatTensor);  // Output: The object is a tensor.
testIsTensor(HalfTensor); 

export default core