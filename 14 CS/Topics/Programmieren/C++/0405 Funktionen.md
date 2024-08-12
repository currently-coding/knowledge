---
tags:
  - cpp
links:
---
## Overview


## Compileroptimierung
### Inline
- `inline bool empty();`
-> Aufrufe werden durch Funktionsrumpf im Code ersetzt(bei kleinen Funktionen sinnvoll)
- bei Memberfunktionen implizit, wenn direkt implementiert
```cpp
class Person {
	int age;

	public:
		bool adult() { return age >= 18; }
		inline bool child();
}

inline Person::child() { return age < 18; }
```

## Code Beispiele/Aufgaben


## Flashcards
