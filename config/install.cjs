/* eslint-disable @typescript-eslint/no-var-requires */
const https = require('https')
const fs = require('fs')
const AdmZip = require('adm-zip')

const url = 'https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-2.0.1%2Bcpu.zip'
const downloadPath = 'libtorch-shared-with-deps-latest.zip'
const extractionPath = 'core'

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
	const zip = new AdmZip(zipPath)
	zip.extractAllTo(extractionPath, true)
	if (callback) callback()
}

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