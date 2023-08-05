/* eslint-disable quotes */
'use strict'

import jsTorch from '../index.js'

import t from 'tap'

t.test('Teste de criação de tensor BFloat16', (t) => {
	
	const tensor = jsTorch.Tensor([123], jsTorch.BFloat16)
	const result = tensor.data()

	t.equal(123, Number(result), `Tensor BFloat16`)

	t.end()
})

t.test('Teste de criação de tensor Bool', (t) => {
	
	const tensor = jsTorch.Tensor([false], jsTorch.Bool)
	const result = tensor.data()

	t.equal(true, Boolean(result), `Tensor Bool`)

	t.end()
})

t.test('Teste de criação de tensor Float', (t) => {
	
	const tensor = jsTorch.Tensor([123], jsTorch.Float)
	const result = tensor.data()

	t.equal(123, Number(result), `Tensor Float`)

	t.end()
})

t.test('Teste de criação de tensor Double', (t) => {
	
	const tensor = jsTorch.Tensor([123], jsTorch.Double)
	const result = tensor.data()

	t.equal(123, Number(result), `Tensor Double`)

	t.end()
})

t.test('Teste de criação de tensor Half', (t) => {
	
	const tensor = jsTorch.Tensor([123], jsTorch.Half)
	const result = tensor.data()

	t.equal(123, Number(result), `Tensor Half`)

	t.end()
})

t.test('Teste de criação de tensor Char', (t) => {
	
	const tensor = jsTorch.Tensor([1], jsTorch.Char)
	const result = tensor.data()

	t.equal(1, Number(result), `Tensor Char`)

	t.end()
})

t.test('Teste de criação de tensor Int', (t) => {
	
	const tensor = jsTorch.Tensor([123], jsTorch.Int)
	const result = tensor.data()

	t.equal(123, Number(result), `Tensor Int`)

	t.end()
})

t.test('Teste de criação de tensor Byte', (t) => {
	
	const tensor = jsTorch.Tensor([1], jsTorch.Byte)
	const result = tensor.data()

	t.equal(1, Number(result), `Tensor Byte`)

	t.end()
})

t.test('Teste de criação de tensor Long', (t) => {
	
	const tensor = jsTorch.Tensor([12345], jsTorch.Long)
	const result = tensor.data()

	t.equal(12345, Number(result), `Tensor Long`)

	t.end()
})

t.test('Teste de criação de tensor Short', (t) => {
	
	const tensor = jsTorch.Tensor([123], jsTorch.Short)
	const result = tensor.data()

	t.equal(123, Number(result), `Tensor Short`)

	t.end()
})
