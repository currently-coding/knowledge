---
tags:
  - cpp
links:
---
# Variablen
## Allgemeine Variablen
- `const` verhindert Abänderung des Wertes einer Variable
```cpp
const X* x; // pointer auf konstanten Wert vom Typ X
// -> Objekt darf nicht ueber Pointer geaendert werden

X* const x; // konstanter pointer auf Wert vom Typ X
// -> Pointer darf nicht geaendert werden, Objekt darf geaendert werden

const X* const x; // konstanter Pointer auf konstanten Wert vom Typ X
// -> weder Pointer noch Objekt darf geaendert werden
```
## Referenzen
```cpp
const X& x;
X const& x;
// Referenz auf konstanten Wert -> Variable darf nicht ueber Alias geaendert werden

X& const x; // konstante Referenz: REDUNDANT, da Referenzen immer unveraenderlich sind
```
# Funktionen
## Allgemeine Funktionen
## Memberfunktionen
- `const` Memberfunktionen sind **Inspektoren** -> lesender Zugriff
- können in Funktion nur weitere `const` Memberfunktionen aufrufen
### Const Overloading
- mehrere gleichnamige, gleich parametrierte Memberfunktionen die sich nur durch `const`unterscheiden
```cpp
std::string& data { return data_; }
const std::string& data const { return data_; }
```
- Compiler wählt passende Variante anhand von Typregeln aus
	- Zuweisung zu `const` vs nicht-`const` Variable
# Code Beispiele/Aufgaben
## Funktionen
### Allgemeine Funktionen
### Memberfunktionen
#### Const Overloading
```cpp
class data_holder {
	private: std::string data_;
	public:
		data_holder(const std::string& data): data_(data) {}
		const std::string& data() const {
			std::cout << "getting const " << data_ << std::endl;
			return data_;
		}
	std::string& data() {
std::cout << "getting non-const " << data_ << std::endl;
return data_;
}};
int main() {
data_holder d("hello");
std::string& nc_data = d.data();
nc_data = "hello world";
std::cout << d.data() << std::endl;
const data_holder& cd(d);
const std::string& c_data = cd.data();
//c_data = "error!";
std::cout << cd.data() << std::endl;
}
```
# Flashcards
