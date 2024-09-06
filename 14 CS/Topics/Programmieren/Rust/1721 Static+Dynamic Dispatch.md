---
links: "[[100 Generic Types, Traits and Lifetimes]]"
---
---
## Was ?
### Static Dispatch
- performed by [[1722 Monomorphization|monomorphized]] code
- compiler knows which functions generic code needs to call depending on the type replacing the generic parts
### Dynamic Dispatch
- compiler can't tell which method a *trait object* is calling as the type hasn't been defined yet([[1720 Trait Objects]])
-> compiler emits code that will figure out which methods to call *during runtime*
#### How ?
- Runtime:
	- *Pointers* inside trait objects point to the objects relative methods
	- lookup occurs on *runtime* <-> [[#Static Dispatch]] is performed during compile time
<!--SR:!2000-01-01,1,250!2024-08-21,4,270-->
	-> prevents some optimizations during compile time
<!--SR:!2024-08-21,4,270-->
	-> more flexibility within our code
## Code Beispiele/Aufgaben


## Flashcards
