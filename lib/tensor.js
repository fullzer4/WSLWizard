import Core from './addon.cjs'

class CTensor {
	constructor(data, dtype) {
		switch (dtype) {
		case 'BFloat16':
            
			this.data = new Core.BFloar16Tensor(data)
			this.dtype = dtype

			break

		case 'Bool':
            
			this.data = new Core.BoolTensor(data)
			this.dtype = dtype

			break

		case 'Byte':
            
			this.data = new Core.ByteTensor(data)
			this.dtype = dtype

			break

		case 'Char':
            
			this.data = new Core.CharTensor(data)
			this.dtype = dtype

			break

		case 'Double':
            
			this.data = new Core.DoubleTensor(data)
			this.dtype = dtype

			break

		case 'Float':
            
			this.data = new Core.FloatTensor(data)
			this.dtype = dtype

			break

		case 'Half':
            
			this.data = new Core.HalfTensor(data)
			this.dtype = dtype

			break

		case 'Int':
            
			this.data = new Core.IntTensor(data)
			this.dtype = dtype

			break

		case 'Long':
            
			this.data = new Core.LongTensor(data)
			this.dtype = dtype

			break

		case 'Short':
            
			this.data = new Core.ShortTensor(data)
			this.dtype = dtype

			break
		}
	}


}

const Tensor = (data, dtype) => {
	return new CTensor(data, dtype)
}

export default Tensor