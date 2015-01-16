use std::os;

/*struct Point {
    x : int,
    y : int,
}*/

#[cfg(not(test))]
fn add_one(x : &int) -> int {
    *x + 1
}

#[cfg(not(test))]
fn main() {
    let args = os::args;
    println!("{}", args[1]);
    hello::print_hello();
    let mut x = 5i;
    println!("The value of x is {}", x);
    x = add_one(&x);
    println!("The value of x is now {}", x);
}

#[cfg(not(test))]
mod hello {
    pub fn print_hello() {
        println!("Hello, World!");
    }
}
