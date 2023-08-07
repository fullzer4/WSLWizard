/* eslint-disable quotes */
'use strict'

import jsTorch from '../index.js'
import t from 'tap'

const tensorTypes = [
	{ type: jsTorch.BFloat16, expectedValue: 123 },
	{ type: jsTorch.Bool, expectedValue: true },
	{ type: jsTorch.Float, expectedValue: 123 },
	{ type: jsTorch.Double, expectedValue: 123 },
	{ type: jsTorch.Half, expectedValue: 123 },
	{ type: jsTorch.Char, expectedValue: 1 },
	{ type: jsTorch.Int, expectedValue: 123 },
	{ type: jsTorch.Byte, expectedValue: 1 },
	{ type: jsTorch.Long, expectedValue: 12345 },
	{ type: jsTorch.Short, expectedValue: 123 },
]

tensorTypes.forEach(({ type, expectedValue }) => {
	t.test(`Teste de criação de tensor ${type.name}`, (t) => {
		const tensor = jsTorch.Tensor([expectedValue], type)
		const result = tensor.data()
    
		t.equal(expectedValue, Number(result), `Tensor ${type.name}`)
		t.end()
	})
})
