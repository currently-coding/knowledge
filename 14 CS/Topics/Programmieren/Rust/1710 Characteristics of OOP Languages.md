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
> Encapsulation := code using an object can't access its implementation details

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
> Inheritance := mechanism whereby an object can inherit elements from another object's definition, thus gaining the parent object's data and behaviour without you having to define them again

-> Rust does **not** have inheritance
### Reasons for Use of Inheritance
#### Reuse Implementation
- possible in a limited way with `traits` in Rust([[102 Traits: Defining Shared Behaviour]])
#### Type System
- Inheritance enables a child to be used the same way a parent type could be used -> `Polymorphism`

> **Polymorphism**
> 
> To many people, polymorphism is synonymous with inheritance. But it’s actually a more general concept that refers to code that can work with data of multiple types. For inheritance, those types are generally subclasses.
> 
> Rust instead uses generics to abstract over different possible types and trait bounds to impose constraints on what those types must provide. This is sometimes called _bounded parametric polymorphism_.

## Flashcards
How does Rust implement Methods(Behaviour) on "Objects"(defined as a type holding data) ;; `struct`  act like objects as their fields can be set to private while the struct is public. On a struct you can - under the use of the `impl` keyword - define methods
<!--SR:!2024-06-17,56,312-->

Does Rust implement encapsulation? If yes, how ? ;; Yes, the `pub` keyword exposes something, while everything else is encapsulated and private by default
<!--SR:!2024-06-04,45,292-->

What is Encapsulation ? ;; Implementation details are hidden to external code using our objects, therefore the implementation can change without affecting the external code. e.g. types can change as long as method signatures stay the same without affection external code.
<!--SR:!2024-06-15,55,310-->

Does Rust Implement Inheritance ? ;; No. Although Rust does implement some limited functionality to enable inheritance in specific cases([[102 Traits: Defining Shared Behaviour]])
<!--SR:!2024-06-04,32,252-->

What is Inheritance ? ;; _Inheritance_ is a mechanism whereby an object can inherit elements from another object’s definition, thus **gaining the parent object’s data and behavior** without you having to define them again. This allows for children types to be used in any place the parent type could've been used, as well as children using the parents methods on themselves.
<!--SR:!2024-05-20,33,292-->

What is **Polymorphism** ? Does Rust implement it ? If yes, how ? ;; To many people, polymorphism is synonymous with inheritance. But it’s actually a more general concept that refers to **code that can work with data of multiple types**. For inheritance, those types are generally subclasses. Rust instead uses **generics** to abstract over different possible types and **trait bounds to impose constraints** on what those types must provide. This is sometimes called _bounded parametric polymorphism_.
<!--SR:!2024-06-03,41,272-->

Summarize the different OOP concepts Rust implements. ?? - Encapsulation(implementation is hidden from external code -> can be changed/modified without need to change external code)
- Objects(`structs`) that contain data and can have methods defined on them.
- Rust does not(or extremely limited) support inheritance. 
- Polymorphism is represented by generics and trait bounds to impose constraints on types
<!--SR:!2024-04-09,4,270-->