import addon from './pkg/main.cjs'

export class CjsTorch {
	constructor() {
		this.addon = addon
	}

	version() { return addon.version() }

	zeros() {
		
	}
}

const jsTorch = new CjsTorch()

console.log(jsTorch.version())
console.log(jsTorch.zeros)

export default jsTorch