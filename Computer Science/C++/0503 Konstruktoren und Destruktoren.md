---
tags:
  - cpp
links:
---
# Content
- [[#Konstruktoren]]
- [[#Destruktoren]]

# Konstruktoren
>spezielle Methode die bei der Erzeugung eines Objektes aufgerufen wird und die Attribute des Objektes initialisiert

## Default Konstruktor
- initialisiert alles mit Default Werten
## Parametrisierte Konstruktoren
```cpp
class Person {
	private:
		int age_;
		int wealth_;
		std::string name_;
	public:
		Person(int age, int wealth, std::string name) {
			age_ = age;
			wealth_ = wealth;
			name_ = name;
		}
}
```
-> Problem:
<!--SR:!2024-08-21,4,270-->
- 

## Explicit Konstruktoren
- Konstruktoren ermoeglichen zunaechset *implizite Konvertierung*
```cpp
class stack {
	private:
		// ...
	public:
		stack(int limit) { /* ... */ } // implicit
		explicit stack(int limit { /* ... */ }) // explicit
}

int main() {
	stack s = 23; // implizite Konvertierung mit stack(23) // implicit
	stack s = 23; // mit explizitem Konstruktor nicht moeglich
}
```

# Destruktoren


# Code Beispiele/Aufgaben


# Flashcards
