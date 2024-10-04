# Implicit Deref Coercions with Functions and Methods
**Deref Coercion converts a *reference* to a type that implements the `Deref` trait into a reference to another type**

Example:
- *deref coercion* can convert `&String` to `&str` 
- `String` implements the `Deref` trait such that it returns `&str`
*Deref Coercion* was implemented to avoid having to add `&` and `*` as a programmer
More code can work with [[0420 References and Borrowing|References]] or [[1500 Smart Pointers|Smart Pointers]]
`Deref::deref` will be called as many times as needed to match the parameter's type
## Code Examples
- `MyBox` has been implemented in previous chapters
	- Deref: `&MyBox<String>` -> `&String`
```rust
fn hello(name: &str) {
	println!("Hello, {name}");
}
```

```rust
fn main() {
	let m = MyBox::new(String::from("Hello"));
	// called with Deref on MyBox and then Deref on &String -> &str => works
	hello(&m);
}
```
- Without *Deref Coercion*
```rust
fn main() {
    let m = MyBox::new(String::from("Rust"));
    hello(&(*m)[..]);
}
```
- `(*m)`: `MyBox<String>` -> `String`
- `&` + `[..]`: takes a `string slice` of the `String`: `String` -> `&str`
=> **Code without `Deref Coercion` is hard to read**
