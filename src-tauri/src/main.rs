#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use tauri::{CustomMenuItem, SystemTray, SystemTrayEvent, SystemTrayMenu, SystemTraySubmenu};
use tauri::Manager;

mod wsl;
use crate::wsl::{
    list::{list_wsl_distributions},
    distro_c::open_distro,
};

fn main() {

    let tray_menu = SystemTrayMenu::new()
        .add_submenu(
            SystemTraySubmenu::new("WSLs", create_wsl_submenu())
        )
        .add_item(CustomMenuItem::new("quit".to_string(), "Quit"));

    tauri::Builder::default().on_window_event(|event| match event.event() {
        tauri::WindowEvent::CloseRequested { api, .. } => {
          event.window().hide().unwrap();
          api.prevent_close();
        }
        _ => {}
        })
        .system_tray(SystemTray::new().with_menu(tray_menu).with_id("tray"))
        
        .on_system_tray_event(|app, event| match event {
            SystemTrayEvent::RightClick {
                position: _,
                size: _,
                ..
            } => {
            }
            SystemTrayEvent::DoubleClick {
                position: _,
                size: _,
                ..
            } => {
                let window = app.get_window("main").unwrap();
                window.show().unwrap();
                println!("system tray received a double click");
            }
            SystemTrayEvent::MenuItemClick { id, .. } => {
                match id.as_str() {
                "quit" => {
                    std::process::exit(0);
                }
                id if id.starts_with("id_") => {
                    let distro_name = &id[3..];
                    println!("{}", distro_name);
                    if let Err(err) = open_distro(distro_name).await {
                        println!("Error opening WSL distro: {}", err);
                    }
                }
                _ => {}
                }
            }
            _ => {}
        })
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}

fn create_wsl_submenu() -> SystemTrayMenu {
    let mut wsl_submenu = SystemTrayMenu::new();
    
    match list_wsl_distributions() {
        Ok(distributions) => {
            for dist in distributions {
                let dist_name: String = dist.name.clone();
                let dist_id: String = format!("id_{}", dist_name.clone());
                println!("Name: {}", dist_name);
                wsl_submenu = wsl_submenu.add_item(CustomMenuItem::new(dist_id, dist_name));
            }
        }
        Err(err) => {
            println!("Erro ao listar as distribuições do WSL: {}", err);
        }
    }
    
    wsl_submenu
}