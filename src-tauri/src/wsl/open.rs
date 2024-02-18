use std::io;
use std::process::Command;


pub fn open_distro(distro_name: &str) -> io::Result<()> {
    let command = format!("wsl.exe ~ -d {}", distro_name);

    let output = Command::new("cmd")
        .args(&["/C", "start", "cmd", "/k", &command])
        .output()?;
    
    if output.status.success() {
        Ok(())
    } else {
        Err(io::Error::new(io::ErrorKind::Other, "Falha ao executar o comando WSL"))
    }
}
