/* eslint-disable quotes */
'use strict'

import jsTorch from '../index.js'

import t from 'tap'

t.test('Teste de criação de tensor', (t) => {
	
	const tensor = jsTorch.Tensor([123], jsTorch.Int)
	const result = tensor.data()

	t.equal(123, Number(result), `Comparacao de resultado`)

	t.end()
})
