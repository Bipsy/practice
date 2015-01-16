use std::io;

fn main() {
    println!("Type something and then press enter/return");
    let input = io::stdin().read_line().ok().expect("Failed to read line\n");
    println!("{}", input);
}
