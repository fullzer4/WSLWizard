use tauri::{CustomMenuItem, SystemTray, SystemTrayMenu, SystemTrayEvent};
use tauri::Manager;

// Learn more about Tauri commands at https://tauri.app/v1/guides/features/command
#[tauri::command]
fn greet(name: &str) -> String {
    format!("Hello, {}! You've been greeted from Rust!", name)
}

fn main() {
    let tray_menu = SystemTrayMenu::new();
    let system_tray = SystemTray::new()
      .with_menu(tray_menu);
    tauri::Builder::default()
      .system_tray(system_tray)
      .run(tauri::generate_context!())
      .expect("error while running tauri application");
  }
