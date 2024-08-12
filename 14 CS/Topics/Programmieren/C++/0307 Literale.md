---
tags:
  - cpp
links:
---
## Definition

>Ein Literal ist eine Kurzschreibweise für [[0501 Objekte]](Werte) bestimmter Datentypen. Interpretation im Speicher ist Datentyp abhängig.
## Integrale Typen
| Name         | Full Name            | min. Size(bit) | usual Size(bit)              | max. Size(bit) | Example                   |
| ------------ | -------------------- | -------------- | ---------------------------- | -------------- | ------------------------- |
| int          | signed int           | 16             | 32                           | -              | `int i = 42;`             |
| unsigned int | unsigned int         | 16             | 32                           | -              | `unsigned int ui = 42U;`  |
| short        | signed short int     | 8              | 16                           | 16             | `short ss = 42S'`         |
| long         | signed long int      | 32             | -                            | -              | `long sl = 42L`;          |
| long long    | signed long long int | 64             | -                            | -              | `long long sll 42LL;`     |
| char         | char                 | 8              | -                            | -              | `char c = 'c';`           |
| size_t       | size_t               | -              | max. size possible on system | systemspecific | `size_t big = sizeof(x);` |

## Gleitkommazahlen
| Name        | Full Name          | Exponent | Mantisse | Example                      |
| ----------- | ------------------ | -------- | -------- | ---------------------------- |
| float       | signed float       | 8        | 23       | `float sf = 42.0f;`          |
| double      | signed double      | 11       | 52       | `double sd = 125e-8`;        |
| long double | signed long double | 15       | 112      | `long double lsd = 125e-8L;` |

- negative Vorzeichen sind *nicht* Teil des Literals
  - Objekt wird erzeugt und **Negationsoperator** angewendet

## String Literale
- wie in #c 
- String Literale erzeugen Objekte vom Typ `char*`
- können mehrzeilig sein
```cpp
char* mutlinine = R"This // R"..."
is a new
C++ style
multiline literal";

// OLD C Variant
char* multiline = "This\n"
"is an old\n"
"multiline literal\n"; // basically 3 literals connected to 1
```
- in #cpp keine `char*` verwenden! `string` aus der  [[Standard Template Library|STL]] ist besser(unterstützt **UTF-8**)
## Flashcards

Was ist ein Literal ? ;; Ein Literal ist eine Kurzschreibweise für [[0501 Objekte]](Werte) bestimmter Datentypen. Interpretation im Speicher ist Datentyp abhängig.
<!--SR:!2024-05-16,13,290-->

Initialisiere eine Variable mit einem...
- `int`
- `unsigned int`
- `short`
- `long`
- `long long`
- `char`
- `float`
- `double`
- `long double`
... Literal. Gib bei `int`, `short`, `long` und `long long` die Größe in Bit an.
?
- `int i = 42;`
- `unsigned int i = 42U;`
- `short s = 42S;`
- `long l = 42L;`
- `long long ll = 42LL;`
- `char c = 'c';`
- `float f = 42.0f;`
- `double d = 125e-8;`
- `long double ld = 123e-8L;`
- Groessen:
	- `short`: 16 bit
	- `int`: 32 bit
	- `long`: 32 bit
	- `long long`: 64 bit
<!--SR:!2024-05-16,13,290-->

Can a literal represent a negative number ? ;; No. First the object will be created and the this object will be turned negative using the negation operator(Negationsoperator)
<!--SR:!2024-05-16,13,294-->

What are floating-point types, and can you provide examples of them along with their components?
?
- float: Exponent: 8 bits, Mantissa: 23 bits, example: `float sf = 42.0f;`
- double: Exponent: 11 bits, Mantissa: 52 bits, example: `double sd = 125e-8;`
- long double: Exponent: 15 bits, Mantissa: 112 bits, example: `long double lsd = 125e-8L;`
<!--SR:!2024-05-15,6,274-->