import os from 'os'

const platform = os.platform()
export const arch = os.arch()

export let platformName

switch (platform) {
case 'darwin':
	platformName = 'macOS'
	break
case 'linux':
	platformName = 'Linux'
	break
case 'win32':
	platformName = 'Windows'
	break
default:
	platformName = 'Unknown platform'
}

console.log(`Platform: ${platformName}`)
console.log(`Architecture: ${arch}`)
