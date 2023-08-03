'use strict'

import jsTorch from '../index.js'

import t from 'tap'
const test = t.test

test('Teste de criação de tensor', (t) => {
	const data = [[0.11111, 0.222222, 0.3333333]]
	const dtype = jsTorch.Float
  
	const myTensor = jsTorch.tensor(data, dtype)

	t.end()
})
