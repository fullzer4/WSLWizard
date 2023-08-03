
import Tensor from './lib/tensor.js'
import Types from './lib/types.js'

class Functions {
	constructor() {
		// Tensor creator
		this.Tensor = Tensor

		// Tensor types
		this.BFloat16 = Types.BFloat16
		this.Bool = Types.Bool
		this.Byte = Types.Byte
		this.Char = Types.Char
		this.Double = Types.Double
		this.Float = Types.Float
		this.Half = Types.Half
		this.Int = Types.Int
		this.Long = Types.Long
		this.Short = Types.Short
	}
}

const jsTorch = new Functions()

export default jsTorch