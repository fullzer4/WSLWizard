/* eslint-disable @typescript-eslint/no-var-requires */
const fs = require('fs')
const os = require('os')
const path = require('path')

const platform = os.platform()
const arch = os.arch()

const binaryPath = path.join(__dirname, '..', `bin/${platform}-${arch}`, 'jstorch.node')
const targetPath = path.join(__dirname, '..', 'lib', 'jstorch.node')

console.log(binaryPath)

try {
	fs.copyFileSync(binaryPath, targetPath)
	console.log('Binary configuration successfully.')
} catch (error) {
	console.error('Platafrom not supported:', error)
}