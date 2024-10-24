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