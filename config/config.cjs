/* eslint-disable @typescript-eslint/no-var-requires */
const { downloadFile, extractZip } = require('./install.cjs')
const fs = require('fs')

const url = 'https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-2.0.1%2Bcpu.zip'
const downloadPath = 'libtorch-shared-with-deps-latest.zip'
const extractionPath = 'core'

downloadFile(url, downloadPath, error => {
	if (error) {
		console.error('Download error:', error)
		return
	}

	console.log('Download complete.')

	extractZip(downloadPath, extractionPath, () => {
		console.log('Extract with success.')

		fs.unlink(downloadPath, err => {
			if (err) {
				console.error('Error removing ZIP file:', err)
			} else {
				console.log('ZIP file removed.')
			}
		})
	})
})