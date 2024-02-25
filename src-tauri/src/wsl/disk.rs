extern crate winapi;

use std::ptr;
use std::mem;
use winapi::um::pdh::{PdhOpenQuery, PdhAddCounterW, PdhCollectQueryData, PdhGetFormattedCounterValue, PdhCloseQuery, PDH_FMT_DOUBLE, PDH_INVALID_HANDLE};
use winapi::um::pdh::PDH_STATUS;
use winapi::um::pdh::PDH_INVALID_DATA;
use winapi::um::winnt::HRESULT;
use std::ffi::OsStr;
use std::os::windows::ffi::OsStrExt;
use std::ptr::null_mut;

pub fn getDiskUsage() {
    let mut query: PDH_HQUERY = ptr::null_mut();
    let mut counter: PDH_HCOUNTER = ptr::null_mut();

    unsafe {
        let status = PdhOpenQueryW(null_mut(), 0, &mut query);
        if status != 0 {
            println!("Failed to open query: {}", status);
            return;
        }

        let counter_path = OsStr::new("\\LogicalDisk(C:)/% Disk Time").encode_wide().chain(Some(0).into_iter()).collect::<Vec<_>>();
        let status = PdhAddCounterW(query, counter_path.as_ptr(), 0, &mut counter);
        if status != 0 {
            println!("Failed to add counter: {}", status);
            PdhCloseQuery(query);
            return;
        }

        let status = PdhCollectQueryData(query);
        if status != 0 {
            println!("Failed to collect query data: {}", status);
            PdhCloseQuery(query);
            return;
        }

        let mut counter_type = 0;
        let mut value: PDH_FMT_COUNTERVALUE = mem::zeroed();
        let status = PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE, &mut counter_type, &mut value);
        if status != 0 {
            if status == PDH_INVALID_DATA as HRESULT {
                println!("No data available for counter");
            } else {
                println!("Failed to get counter value: {}", status);
            }
            PdhCloseQuery(query);
            return;
        }

        println!("Disk usage: {:.2}%", value.doubleValue);
    }

    unsafe {
        PdhCloseQuery(query);
    }
}