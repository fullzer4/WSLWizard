/* eslint-disable @typescript-eslint/no-var-requires */
const https = require('https')
const fs = require('fs')
const unzipper = require('unzipper')

const url = 'https://download.pytorch.org/libtorch/nightly/cpu/libtorch-shared-with-deps-latest.zip'
const downloadPath = 'libtorch-shared-with-deps-latest.zip'
const extractionPath = 'lib'

function downloadFile(url, downloadPath, callback) {
	const file = fs.createWriteStream(downloadPath)

	https.get(url, response => {
		response.pipe(file)
		file.on('finish', () => {
			file.close(callback)
		})
	}).on('error', error => {
		fs.unlink(downloadPath, () => {
			if (callback) callback(error)
		})
	})
}

function extractZip(zipPath, extractionPath, callback) {
	fs.createReadStream(zipPath)
		.pipe(unzipper.Extract({ path: extractionPath }))
		.on('close', callback)
}

downloadFile(url, downloadPath, error => {
	if (error) {
		console.error('Download error:', error)
		return
	}

	console.log('Download complete.')

	extractZip(downloadPath, extractionPath, () => {
		console.log('Extract with sucess.')
		fs.unlink(downloadPath, err => {
			if (err) {
				console.error('Error removing ZIP file:', err)
			} else {
				console.log('ZIP file removed.')
			}
		})
	})
})