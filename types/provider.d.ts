import Tensor, { CTensor } from './tensor'
import { Types } from './types'

class Functions {
	// eslint-disable-next-line @typescript-eslint/no-explicit-any
	Tensor: (data: any, dtype: string) => CTensor

	BFloat16: 'BFloat16'
	Bool: 'Bool'
	Byte: 'Byte'
	Char: 'Char'
	Double: 'Double'
	Float: 'Float'
	Half: 'Half'
	Int: 'Int'
	Long: 'Long'
	Short: 'Short'

	constructor() {
		this.Tensor = Tensor

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

const jsTorch: Functions

export default jsTorch