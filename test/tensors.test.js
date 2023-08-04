/* eslint-disable quotes */
'use strict'

import jsTorch from '../index.js'

import t from 'tap'
const test = t.test

test('Teste de criação de tensor', (t) => {
	const data = [[0.11111, 0.222222, 0.3333333]]
	const dtype = jsTorch.Double
  
	const myTensor = jsTorch.Tensor(data, dtype)

	const result = myTensor.data()

	t.equal(42, result, `Comparacao de resultado`) // mudar para um teste valido depois

	t.end()
})
