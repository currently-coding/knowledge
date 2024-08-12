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


## Flashcards
How does a **trait object** work ? :: It points to an *instance of the type implementing the specific trait* and a *table to look up trait methods on that type at runtime*
<!--SR:!2024-05-05,12,250-->

Explain the difference in code behaviour between using **trait objects** and **generics + trait bounds**.
?
**Generics** will be replace with 1 specific type at compile time, thus a vector cannot be filled with different types all implementing the trait. In contrast **trait objects** stored in a vector allow for different types to be stored as long as they implement the trait without breaking the homogeneous character of the vector. **Trait objects** enhance our code at a small performance cost with more flexibility. **Generics** just become 1 specific type at compile time, which does not add much flexibility besides being able to call functions/methods with different types as parameters consecutively. E.g. `Vector`:
- Generic: Vector can only store type `a`
- Trait object: Vector can store types `a`, `b`, `c`, etc. as long as they implement a trait
<!--SR:!2024-05-14,24,270-->