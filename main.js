import addon from './pkg/main.cjs'

export class CjsTorch {
	constructor() {
		this.addon = addon
	}

	version() { return addon.version() }

	zeros( rows, cols ) { return new addon.zeros(rows, cols) }

	ones( rows, cols ) { return new addon.ones(rows, cols) }
}

const jsTorch = new CjsTorch()

console.log(jsTorch.version())
console.log(jsTorch.zeros(2,3))
console.log(jsTorch.ones(2,3))

export default jsTorch