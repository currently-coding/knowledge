---
tags:
  - cpp
links: "[[0508 Klassenfunktionen]]"
---
# Allgemein

>Variablen, die in allen Instanzen den gleichen Wert haben

- `static` erstellt Klassenvariablen
- müssen außerhalb der Klassendefinition initialisiert werden
```cpp
class Widget {
	private:
		static int count;
	public:
		Widget() { count++; }
		~Widget() { count--; }
}

Widget::count = 0; // initialisierung ausserhalb der Klasse
```
## Zugriff
1. Instanz: `instance.static_var;`
2. Klassen: `MyClass::static_var;` **empfohlen**

# Code Beispiele/Aufgaben


# Flashcards
