#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("cpp/src/main.cpp");

        include!("cpp/src/lib/employee.h");
        // include!("cpp/src/lib/utils.h");

        fn app();
    }
}

fn main() {
    ffi::app();
}
