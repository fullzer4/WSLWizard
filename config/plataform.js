import os from 'os'

export const platform = os.platform()
export const arch = os.arch()

console.log(`Platform: ${platform}`)
console.log(`Architecture: ${arch}`)