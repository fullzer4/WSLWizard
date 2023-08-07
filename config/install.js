import { platformName } from './plataform.js'
import https from 'https'
import unzipper from 'unzipper'

async function downloadAndExtract(url) {
	https.get(url, (response) => {
		if (response.statusCode !== 200) {
			console.error('Erro ao fazer o download:', response.statusCode)
			return
		}
		response.pipe(unzipper.Extract({ path: './libtorch' }))
			.on('error', (error) => {
				console.error('Erro ao extrair o arquivo ZIP:', error)
			})
			.on('close', () => {
				console.log('Extração concluída com sucesso.')
			})
	}).on('error', (error) => {
		console.error('Erro ao fazer o download:', error)
	})
}

const urls = {
	macOS: 'https://download.pytorch.org/libtorch/cpu/libtorch-macos-2.0.1.zip',
	Linux: 'https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-2.0.1+cpu.zip',
	Windows: 'https://download.pytorch.org/libtorch/cpu/libtorch-win-shared-with-deps-2.0.1+cpu.zip'
}

const url = urls[platformName]
if (url) {
	() => downloadAndExtract(url)
} else {
	console.log('Plataforma não suportada.')
}
