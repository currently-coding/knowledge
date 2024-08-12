---
tags:
  - cpp
links:
---
# Konstante Variablen
```cpp
const int my_constant_int = 42;
```
- unveränderlicher Wert
- müssen direkt initialisiert werden
```cpp
const int num; // ERROR
```
## Konstanten und Pointer
- **Von rechts nach links lesen**
#### Pointer auf Konstante Werte
```cpp
// num ist ein konstanter Integer
const int num = 42

// num_pointer ist ein Pointer auf einen konstanten Integer
const int* num_pointer = &num;
int const* num_pointer
```
#### Konstante Pointer
```cpp
// num ist ein Integer
int num = 42;

// num_pointer ist ein konstanter Pointer auf einen Integer
int* const num_pointer = &num;
```
#### Konstante Pointer auf Konstante Werte
```cpp
// num ist ein konstanter Integer
const int num = 42;

// num_pointer ist ein konstanter Pointer auf einen konstanten Integer
const int* const num_pointer = &42;
```


# Code Beispiele/Aufgaben
[]()

# Flashcards
