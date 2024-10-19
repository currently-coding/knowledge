---
tags:
  - "#rust"
links:
---
## When to use
- Need to have multiple types of data stored in a homogeneous field(e.g. `vector`) 

## How ?
```Rust
pub trait ExampleTrait {
	// every type using the trait needs to implement this funciton
	fn exampleFunction(&self);
}
```
See [[102 Traits: Defining Shared Behaviour]] for full explanation

### Example: GUI
```Rust
pub trait Draw {
	fn draw(&self);
}
```
```Rust
pub struct Screen {
	// vector can hold *trait objects* that implement the `Draw` trait
	pub components: Vec<Box<dyn Draw>>,
}

impl Screen {
	pub fn run(&self) {
		for component in self.components.iter() {
			component.draw();
		}
	}
}
```
- `vector` can only hold *trait objects* - different from an implementation using generics and trait bound
- `vector` can hold `Box<Button>`, `Box<TextField` and more as its holding *trait objects*
#### Generic + Trait bound implementation
```Rust
pub struct Screen<T: Draw> { // requiring a type T to implement the `Draw` trait
	pub components: Vec<T>,
}

impl<T> Screen<T>
where
	T: Draw
{
	pub fn run(&self) {
		for component in self.components.iter() {
			component.draw();
		}
	}
}
```
-> T will be *monomorphized* at compile time, thus a concrete type will replace `T` leading to a homogeneous vector and the limitation to one type `T` that's implementing `Draw`
- e.g. Screen struct field components can only hold data of type `Box<Button>` but not of type `Box<TextField>` as the `vector` needs to be homogeneous

#### Runtime Performance
##### Generics + Traitbounds
- **Monomorphization** 
	- compiler generates *non-generic implementations of functions and methods for each concrete type*
	- resulting code does *[[1721 Static+Dynamic Dispatch|static dispatch]]*
## Code Beispiele/Aufgaben

