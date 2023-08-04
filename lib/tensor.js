import Core from './addon.cjs'

class CTensor {
	constructor(data, dtype) {
		switch (dtype) {
		case 'BFloat16':
            
			this._data = new Core.BFloar16Tensor(data)
			this.dtype = dtype

			break

		case 'Bool':
            
			this._data = new Core.BoolTensor(data)
			this.dtype = dtype

			break

		case 'Byte':
            
			this._data = new Core.ByteTensor(data)
			this.dtype = dtype

			break

		case 'Char':
            
			this._data = new Core.CharTensor(data)
			this.dtype = dtype

			break

		case 'Double':
            
			this._data = new Core.DoubleTensor(data)
			this.dtype = dtype

			break

		case 'Float':
            
			this._data = new Core.FloatTensor(data)
			this.dtype = dtype

			break

		case 'Half':
            
			this._data = new Core.HalfTensor(data)
			this.dtype = dtype

			break

		case 'Int':
            
			this._data = new Core.IntTensor(data)
			this.dtype = dtype

			break

		case 'Long':
            
			this._data = new Core.LongTensor(data)
			this.dtype = dtype

			break

		case 'Short':
            
			this._data = new Core.ShortTensor(data)
			this.dtype = dtype

			break
		}
	}

	data() {
		return this._data.data();
	}
	
}

const Tensor = (data, dtype) => {
	return new CTensor(data, dtype)
}

export default Tensor