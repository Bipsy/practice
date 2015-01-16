extern crate modules;
use modules::add_three_times_four;

#[test]
fn foo() {
    assert!(true);
}

#[test]
fn bar() {
    assert_eq!(16, add_three_times_four(1));
}
