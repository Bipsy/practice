use std::io;
use std::rand;

struct Property {
    name : String,
    price : int,
}

fn get_numeric_input() -> int {
    let input = io::stdin().read_line()
                           .ok().expect("Failed to getline\n");
    let input_num: Option<int> = from_str(input.as_slice().trim());
        
    let num = match input_num {
        Some(num) => num,
        None => {
            return -1;
        },
    };
    num
} 

fn print_money(player_money: int) {
    println!("You have ${} dollars!", player_money); 
}

fn add_money(player_money : int) -> int {
    println!("How much money would you like to add?");
    let num = get_numeric_input();
    match num {
        x if x < 0 => {
            println!("Invalid amount");
            player_money
        },
        _ => player_money - num
    }
}

fn spend_money(player_money : int) -> int {
    println!("How much money would you like to spend?");
    let num = get_numeric_input();
    let res = match num {
        x if x < 0 => {
            println!("Invalid amount");
            player_money
        },
        x if player_money - x < 0 => {
            println!("You don't have that much money to spend.");
            player_money
        },
        _ => player_money - num,
    };
    res
}

fn roll_dice() -> uint {
    let dice_one = (rand::random::<uint>() % 6u) + 1;
    let dice_two = (rand::random::<uint>() % 6u) + 1;
    dice_one + dice_two    
}

fn remove_property(player_properties : &mut Vec<Property>, 
                   property_name : &str) {
    let mut counter = 0u;
    for property in player_properties.iter() {
        if property.name == property_name {
            break;
        }
        counter += 1;
    }
    player_properties.swap_remove(counter);
}

fn sell_property(player_properties : &mut Vec<Property>, player_money : int) 
    -> int {
    println!("Type <property name> enter/return\n     \
                   <property price> enter/return");
    let property_name = io::stdin().read_line()
                            .ok().expect("Failed to getline\n");
    let property_price_str = io::stdin().read_line()
                            .ok().expect("Failed to getline\n");
    let option_price : Option<int> =
        from_str(property_price_str.as_slice().trim());
    match option_price {
        Some(price) if price >= 0 => {
            if owns_property(player_properties, property_name.as_slice()) {
                remove_property(player_properties, property_name.as_slice());
                player_money + price
            } else {
                println!("You don't own that property.");
                player_money
            }
        },
        Some(..) => {
            println!("The price you entered is negative.");
            player_money
        }
        None => {
            println!("The price you entered is not an integer.");
            player_money        
        }
    } 
}

fn buy_property(player_properties : &mut Vec<Property>, player_money : int) 
    -> int {
    println!("Type <property name> enter/return\n     \
                   <property price> enter/return");
    let property_name = io::stdin().read_line()
                           .ok().expect("Failed to getline\n");
    let property_price_str = io::stdin().read_line()
                                 .ok().expect("Failed to getline\n");
    let option_price : Option<int> = 
        from_str(property_price_str.as_slice().trim());
    match option_price {
        Some(price) => {
            if owns_property(player_properties, property_name.as_slice().trim()) {
                println!("You already own that property.");
                player_money
            } else if player_money - price < 0 {
                println!("You don't have enough money to purchase \
                          that property.");
                player_money
            } else {
                let property = Property {name : property_name, 
                                         price : price};
                player_properties.push(property);
                player_money - price
            }
        },
        None => {
            println!("Incorrect input");
            player_money
        }
    }
}

fn owns_property(player_properties : &Vec<Property>,
                 property_name : &str) -> bool {
    for property in player_properties.iter() {
        if property.name == property_name {
            return true;
        }
    }
    false
}

fn display_properties(player_properties : &Vec<Property>) {
    for property in player_properties.iter() {
        print!("Name: {}", property.name);
        print!("Price: {}\n", property.price);
    }
}

fn print_options() {
    println!("1. Roll the dice");
    println!("2. Print Money Report");
    println!("3. Add money");
    println!("4. Spend money");
    println!("5. Pass Go");
    println!("6. Buy property");
    println!("7. Sell property");
    println!("8. Display owned properties");
    println!("9. Quit program");    
}

fn main() {
    let start_money = 1500i;
    let mut player_money = start_money;
    let mut player_properties : Vec<Property> = vec![];
    loop {
        print_options();
        let num = get_numeric_input(); 

        match num {
            1 => {
                let dice_roll = roll_dice();
                println!("You rolled a {}!", dice_roll);
                continue;
            }
            2 => {
                print_money(player_money);
            }
            3 => {
                player_money = add_money(player_money);
            }
            4 => {
                player_money = spend_money(player_money);
            }
            5 => {
                player_money += 200;
            }
            6 => {
                player_money = buy_property(&mut player_properties,
                                            player_money);
            }
            7 => {
                player_money = sell_property(&mut player_properties,
                                             player_money);
            }
            8 => {
                display_properties(&player_properties);
            }
            9 => break,
            _ => {
                println!("Invalid option, try again.");
            },
        }
        println!("");
    }
}
