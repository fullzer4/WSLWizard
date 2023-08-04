/* eslint-disable @typescript-eslint/no-explicit-any */
import Core from '../addon.cjs'

declare class CTensor {
	private _data: Core.BFloar16Tensor | Core.BoolTensor | Core.ByteTensor | Core.CharTensor | Core.DoubleTensor | Core.FloatTensor | Core.HalfTensor | Core.IntTensor | Core.LongTensor | Core.ShortTensor
	public dtype: string

	constructor(data: any, dtype: string);
	public data(): any; 
}

export default CTensor

export declare function Tensor(data: any, dtype: string): CTensor;
