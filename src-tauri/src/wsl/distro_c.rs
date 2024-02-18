use std::io;
use std::process::Command;
use std::sync::Arc;
use futures::lock::Mutex;

pub async fn open_distro(distro_name: &str) -> io::Result<()> {
    println!("Comando a ser executado: wsl.exe -d {} --new-window", distro_name);

    let output = Command::new("wsl.exe")
        .args(&["-d", distro_name, "--new-window"])
        .output()
        .await?;

    if output.status.success() {
        println!("foi");
        Ok(())
    } else {
        Err(io::Error::new(io::ErrorKind::Other, "Falha ao executar o comando WSL"))
    }
}