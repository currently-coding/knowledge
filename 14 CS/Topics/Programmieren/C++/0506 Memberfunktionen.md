---
tags:
  - cpp
links:
---
# Allgemein
- müssen auf Objekten ausgeführt werden
```cpp
class Person {
	private:
		int age;
		std::string name;
	public:
		Person(int age, std::string name) : age(age), name(name) {}

		void datenAusgeben() {
			std::cout << "Person " << name << " is " << age << " years old";
		}
}

int main() {
	Person p1; // called paramterlosen Konstruktor und initialisiert

	p1.datenAusgeben(); // ruft Memberfunktion auf p1 auf
}
```
# `const` Memberfunktionen
- oft nicht nötig, dass Memberfunktionen Objektzustände ändern
-> `const` Memberfunktionen: **Inspector**(lesende Funktion) <-> **Mutator**(schreibende Funktion)
- mit `<datentyp> <bezeichner>(<parameter>) const;` deklariert
- `const` Funktionen dürfen [[0505 Membervariablen]] *nicht* ändern
- **`const` Referenzvariablen dürfen nur `const` Memberfunktionen aufrufen**
# Code Beispiele/Aufgaben


# Flashcards
