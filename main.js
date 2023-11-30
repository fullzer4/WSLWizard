import addon from "./pkg/main.cjs"

export class CjsTorch {
    constructor() {
        this.addon = addon
    }
}

const jsTorch = new CjsTorch()

console.log(jsTorch.addon.hello())

export default jsTorch