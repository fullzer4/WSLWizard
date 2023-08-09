/* eslint-disable @typescript-eslint/no-var-requires */
const https = require('https')
const fs = require('fs')
const AdmZip = require('adm-zip')

export function downloadFile(url, downloadPath, callback) {
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

export function extractZip(zipPath, extractionPath, callback) {
	const zip = new AdmZip(zipPath)
	zip.extractAllTo(extractionPath, true)
	if (callback) callback()
}