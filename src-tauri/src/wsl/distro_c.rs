use tauri::{CustomMenuItem, SystemTrayMenu};
use super::list::list_wsl_distributions;

pub fn create_wsl_submenu() -> SystemTrayMenu {

    fn clean_string(input: &str) -> String {
        input.chars().filter(|&c| c.is_ascii_graphic() || c.is_whitespace()).collect()
    }

    let mut wsl_submenu = SystemTrayMenu::new();
    
    match list_wsl_distributions() {
        Ok(distributions) => {
            for dist in distributions {
                let dist_name: String = clean_string(&dist.name);
                let dist_id: String = format!("id_{}", &dist_name);
                wsl_submenu = wsl_submenu.add_item(CustomMenuItem::new(dist_id, dist_name));
            }
        }
        Err(err) => {
            println!("Erro ao listar as distribuições do WSL: {}", err);
        }
    }
    
    wsl_submenu
}
