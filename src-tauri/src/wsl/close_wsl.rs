use std::io;
use std::process::Command;


pub fn close_wsl() -> io::Result<()> {

    let output = Command::new("wsl.exe")
        .args(&["--shutdown"])
        .output()?;
    
    if output.status.success() {
        Ok(())
    } else {
        Err(io::Error::new(io::ErrorKind::Other, "Falha ao executar o comando WSL"))
    }
}
