'use strict'

import core from '../index.js'

import t from "tap"
const test = t.test
test('test float tensor creation', t => {
    t.plan(1)
    const TensorBase = new core.TensorBase();
    t.ok(TensorBase.IsTensor())
})


test('test float tensor creation', t => {
    t.plan(2)
    const FloatTensor = new core.FloatTensor();
    t.ok(FloatTensor.IsTensor())
})

test('test double tensor creation', t => {
    t.plan(3)
    const DoubleTensor = new core.DoubleTensor();
    t.ok(DoubleTensor.IsTensor())
})

test('test half tensor creation', t => {
    t.plan(4)
    const HalfTensor = new core.HalfTensor();
    t.ok(HalfTensor.IsTensor())
})