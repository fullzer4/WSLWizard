import Core from './addon.cjs'

class CCuda {
	constructor() {

		this._cuda = new Core.Cuda()
	}

	is_avaliable() {
		return this._cuda.IsAvailable
	}
	
}

const Cuda = () => {
	return new CCuda()
}

export default Cuda