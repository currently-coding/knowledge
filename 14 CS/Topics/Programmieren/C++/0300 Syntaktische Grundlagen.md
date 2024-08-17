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

## Flashcards
Literale: Gib die Datentypen folgender Literale an:
- `0`
- `1.0`
- `"Hello"`
- `false`
- `0.1f`
?
- `int`
- `double`
- `String`
- `boolean`
- `float`

<!--SR:!2024-08-30,13,294-->

Was sind Präprozessor-Anweisungen in C++ und wofür werden sie benutzt? :: Präprozessor-Anweisungen sind Anweisungen, die vom Präprozessor ausgeführt werden, bevor die eigentliche Kompilierung de Programms beginnt. Sie beginnen mit dem Symbol `#` und dienen verschiedenen Zwecken wie dem Einbinden von Headerdateien, der Definition von Makros oder Konstanten sowie der bedingten Kompilierung.

<!--SR:!2024-08-23,6,270-->

Können Sie einige Beispiele für Präprozessor-Direktiven in C++ nennen und ihre Verwendung erklären?
?
- `#include`: Inkludiert Headerdateien.
- `#define`: Definiert Makros oder Konstanten.
- `#ifdef`, `#ifndef`, `#if`, `#else`, `#endif`: Ermöglichen bedingte Kompilierung.
- `#pragma once`: Stellt sicher, dass Headerdateien nur einmal eingebunden werden.

<!--SR:!2024-10-08,52,310-->

Was sind Schlüsselwörter in C++ und welche Bedeutung haben sie? :: Schlüsselwörter sind reservierte Zeichensequenzen in C++, die spezielle Bedeutungen haben und bestimmte Funktionen im Programm definieren. Sie dürfen nicht als Bezeichner verwendet werden und steuern den Ablauf und die Struktur des Codes.

<!--SR:!2024-12-13,118,290-->

Was sind Literale in C++ und können Sie Beispiele geben? :: Literale sind Kurzschreibweisen für Objekte bestimmter Datentypen. Sie repräsentieren konkrete Werte im Code. Beispiele sind Ganzzahlen wie `0`, Fließkommazahlen wie `1.0`, Zeichenfolgen wie `"Hello"`, Boolesche Werte wie `false` und Gleitkommazahlen wie `0.1f`.

<!--SR:!2024-10-12,56,310-->

Welche Funktion haben Begrenzer in der Programmierung? :: Begrenzer sind Trennzeichen für syntaktische Einheiten im Code. Sie haben eine individuelle, kontextabhängige Bedeutung und werden verwendet, um Ausdrücke, Anweisungen und Strukturen voneinander abzugrenzen, z. B. `, . ; : ? () [] {} <>`.

<!--SR:!2024-08-25,8,270-->


