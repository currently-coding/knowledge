---
tags:
  - "#rust"
---

# Characteristics
- [[#Objects contain Data and Behaviour]]
- [[#Encapsulation to hide implementation details]]
- [[#Inheritance as a Type System and as Code Sharing]]

## Objects contain Data and Behaviour
- No agreed on definition

>Object-oriented programs are made up of objects. An _object_ packages both data and the procedures that operate on that data. The procedures are typically called _methods_ or _operations_.
>	*"Design Patterns: Elements of Reusable Object-Oriented Software*(book)

-> `structs` in Rust can behave like this([[050 Structs]])

## Encapsulation to hide implementation details
> Encapsulation -> code using an object can't access its implementation details

-> implementation details can change without need to change the code depending on the implementation 

-> `pub` keyword in Rust enables this([[070 Packages, Crates and Modules]])
- Example:
```rust
pub struct AveragedCollection { // struct public - fields private
	list: Vec<i32>,
	average: f64,
}
```

```rust
impl AveragedCollection {
    pub fn add(&mut self, value: i32) {
        self.list.push(value);
        self.update_average();
    }

    pub fn remove(&mut self) -> Option<i32> {
        let result = self.list.pop();
        match result {
            Some(value) => {
                self.update_average();
                Some(value)
            }
            None => None,
        }
    }

    pub fn average(&self) -> f64 {
        self.average
    }

    fn update_average(&mut self) {
        let total: i32 = self.list.iter().sum();
        self.average = total as f64 / self.list.len() as f64;
    }
    /*
    multi
    line
    comment
    *
} // useless comments
```
- external code cannot access the `average` field as it is private, thus it will always remain accurate as every other function calls an update function to update `average`
- flexibility to change types, etc. as long as function signatures stay the same

## Inheritance as a Type System and as Code Sharing

-> Rust does **not** have inheritance
### Reasons for Use of Inheritance
#### Reuse Implementation
- possible in a limited way with `traits` in Rust([[102 Traits: Defining Shared Behaviour]])
#### Type System
- Inheritance enables a child to be used the same way a parent type could be used -> `Polymorphism`

>[!Note]
> **Polymorphism**
> 
> To many people, polymorphism is synonymous with inheritance. But it’s actually a more general concept that refers to code that can work with data of multiple types. For inheritance, those types are generally subclasses.
> 
> Rust instead uses generics to abstract over different possible types and trait bounds to impose constraints on what those types must provide. This is sometimes called _bounded parametric polymorphism_.