use std::io;
use std::rand;

fn get_random_number() -> uint {
    let secret_number = (rand::random::<uint>() % 100u) + 1u;
    secret_number
}

fn cmp(a: uint, b: uint) -> Ordering {
    if a < b { Less } 
    else if a > b { Greater }
    else { Equal }
}

fn main() {
    let secret = get_random_number();
    loop {
        println!("Type your guess (between 0 and 100) then press enter/return");
        let input = io::stdin().read_line()
                               .ok().expect("Failed to read line\n");
        let input_num: Option<uint> = from_str(input.as_slice().trim());

        let num = match input_num {
            Some(num) => num,
            None => {
                println!("You didn't type in a number.");
                continue;
            }
        };

        match cmp(num, secret) {
            Less => println!("Too small"),
            Equal => {
                        println!("Just right\nYou Win!");
                        return;
            },
            _ => println!("Too big"),
        };
    }
}
