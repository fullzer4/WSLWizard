import os from 'os'

export const platform = os.platform()
export const arch = os.arch()

let platformName

switch (platform) {
case 'aix':
	platformName = 'IBM_AIX'
	break
case 'darwin':
	platformName = 'Apple_macOS'
	break
case 'freebsd':
	platformName = 'FreeBSD'
	break
case 'linux':
	platformName = 'Linux'
	break
case 'openbsd':
	platformName = 'OpenBSD'
	break
case 'sunos':
	platformName = 'SunOS'
	break
case 'win32':
	platformName = 'Microsoft_Windows'
	break
default:
	platformName = 'Unknown platform'
}

console.log(`Platform: ${platformName}`)
console.log(`Architecture: ${arch}`)
