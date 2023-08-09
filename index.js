
import Tensor from './lib/tensor.js'
import Types from './lib/types.js'
import Core from './lib/addon.cjs'
import Cuda from './lib/cuda.js'

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

		// NN - neural networks module
		this.load = Core.load

		// Cudas - gpu module
		this.cuda = Cuda()
	}
}

const jsTorch = new Functions()

export default jsTorch