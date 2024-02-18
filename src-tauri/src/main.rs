#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use tauri::{CustomMenuItem, SystemTray, SystemTrayEvent, SystemTrayMenu, SystemTraySubmenu};
use tauri::Manager;

mod wsl;
use crate::wsl::{
    distro_c::create_wsl_submenu,
    open::open_distro,
    close_wsl::close_wsl,
};

fn main() {

    fn clean_string(input: &str) -> String {
        input.chars().filter(|&c| c.is_ascii_graphic() || c.is_whitespace()).collect()
    }

    let tray_menu = SystemTrayMenu::new()
        .add_submenu(
            SystemTraySubmenu::new("WSLs", create_wsl_submenu())
        )
        .add_item(CustomMenuItem::new("open".to_string(), "Open menu"))
        .add_item(CustomMenuItem::new("quitWSL".to_string(), "Close WSL"))
        .add_item(CustomMenuItem::new("quit".to_string(), "Close WSLWizard"));

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
                "quitWSL" => {
                    let _ = close_wsl();
                }
                "open" => {
                    let window = app.get_window("main").unwrap();
                    window.show().unwrap();
                }
                id if id.starts_with("id_") => {
                    let distro_name = clean_string(&id[3..]); 
                    if let Err(err) = open_distro(&distro_name) {
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