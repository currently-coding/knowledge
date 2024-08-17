---
tags:
  - cpp
links:
---
# Zeiger
>Ein Zeiger(`pointer`) ist ein [[0511 Objekte|Objekt]], dessen Wert die (Speicher-)Adresse eines anderen Objekts repräsentiert.
```cpp
int main() {
	int i = 42;
	int* p = &i; // pointer auf `i`
	int** pp = &p; // pointer pointer auf i

	int value = *p; // Dereferenzieren von p -> Zugriff auf Wert
	int value2 = **pp; // Dereferenzieren von  -> Zugriff auf Wert
}
```

![[Pasted image 20240501081029.png]]

>Zeiger auf Objekt von Typ `T` hat den Typ `T*`

>Dereferenzieren: Zugriff auf das Objekt, auf welches ein Zeiger verweist

>Indirektionsoperator `*`: zum Dereferenzieren benutzt

>Adressoperator `&`: Wenn `x` ein Objekt vom Typ `T` ist, dass ist `x` seine Adressen und hat den Typ `T*`


- Zeiger sollten - falls nicht direkt mit einer sinnvollen Adresse initialisiert - mit `nullptr` initialisiert werden
	-> **Zeiger zeigt definiert auf nichts**(= Adresswert von 0, der niemals gültig ist)
<!--SR:!2024-08-21,4,270-->
## Anwendung Struct
### Zeiger auf Struct
### Struct mit Zeiger als [[0500 OOP#Membervariablen|Membervariable]]
```cpp
// Linked list
struct List {
	List* next; // pointer to next element
	List* previous; // pointer to previous element
	int value;
}
```

```cpp

```

# Code Beispiele/Aufgaben
![[Pasted image 20240501081220.png]]

# Flashcards
