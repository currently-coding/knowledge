---
tags:
  - cpp
links:
---
## syntaktische Kategorien
- [[#Präprozessor Anweisungen]]
- [[#Kommentare]]
- [[#Schlüsselwörter]]
- [[#Bezeichner]]
- [[#Literale]]
- [[#Begrenzer]]
- [[#Operatoren]]

## Präprozessor Anweisungen
- **preprocessor directives**
- vom Präprozessor ausgeführt
- *nicht* teil der C++ Sprache
- starten mit `#`
- Nutzung
	- including header files
	- defining constants(bad style in C++)
	- conditional compilation
	- more
### Preprocessor Directives
```cpp
#include <iostream>

#define PI 3.14159265358979323

#ifdef DEBUG
	#define LOG(x) std::cout << x << std::endl
#else 
	#define LOG(x)
#endif

#pragma once
```
- `#include` includes header files (`<name>.h`)
- `#define` definiert [[0403 macros|macros]] oder [[0301 Konstanten|constants]]
- `#ifdef`, `#ifndef`, `##if`, `#else`, `#endif`: [[0402 Conditional Compilation|conditional compilation]]
- `#pragma once` stellt sicher, das [[0303 Header Files|header files]] nur ein Mal includet werden(generell: an/abschalten bestimmter [[0400 Compiler|compiler]] features)
- More: [[0401 Preprocessor Directives]]

## Kommentare
- werden vom [[0400 Compiler|compiler]] *ignoriert*
```cpp
// single line comment

/* 
multi
line
comment
*/
```

## Schlüsselwörter
- **keywords**
- Liste aller [[0302 Schlüsselwörter|Schlüsselwörter]]
- reservierte Zeichensequenzen
- dürfen *nicht* als Bezeichner verwendet werden
- More: [[0302 Schlüsselwörter]]

## Bezeichner
- Namen von [[0404 Variablen|Variablen]], [[0405 Funktionen|Funktionen]], [[0406 Datentypen|Datentypen]] und allen **deklarierbaren** Elementen
```cpp
double calculate_factorial_function();
const DELIMITER_30 = 30;
int my_var = 10;
// ...
```
- More: [[0306 Bezeichner]]

## Literale
- Kurzschreibweise für [[0501 Objekte|Objekte]](Werte) bestimmter [[0406 Datentypen|Datentypen]]
```cpp
0 // int
1.0 // double
"Hello" // String
false // boolean
0.1f // float
```
- More: [[0307 Literale]]

## Begrenzer
- Trenner für syntaktische Einheiten
- individuelle, kontextabhängige Bedeutung
- `, . ; : ? () [] {} <>`

## Operatoren
- Bestandteil von [[0304 Ausdrücke|Ausdrücken]] oder [[0305 Anweisungen]]
-  individuelle, kontextabhängige Bedeutung
- More: [[0308 Operatoren]]
## Code Beispiele/Aufgaben
```cpp
include <iostream> // preprocessor directive: including header file
#define number unsigned int // preprocessor directive: macro

// calculate the factorial of a nonnegative number // comment
number factorial(number n) { // function signature: bezeichner, begrenzer
	if (n <= 1) { // keyword, begrenzer
		return 1; // keyword
	}
		return n * factorial(n-1);
	}

int main(int argc, char **argv) {
	using namespace std;
	int n = atoi(argv[1]); // first command line parameter
	int x = factorial(n);
	cout << "The factorial of " << n << " is " << x << endl;
	return 0;
}
```




