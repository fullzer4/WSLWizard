import t from 'tap'
import jsTorch from '../main.js'

t.test('Test for import modules', t => {
    t.equal(jsTorch.addon.hello(), 'world', 'this passes')
    t.end()
})
