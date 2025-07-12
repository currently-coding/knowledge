---
tags: 
links:
---
# Datentypen
- [[#Boolean]]

# Boolean
| bool    | bool   |
| ------- | ------ |
| `false` | `true` |
- statt integraler Typen(0, 1)
- Theoretischer Speicherbedarf: **1 Bit**
- Praktisch: als `char` umgesetzt
- Konvertierung: `false == 0;` `true != 0;`
- Boolean-Literale(`false, true`): `std::boolalpha`

# Number Types
![[0307 Literale#Integrale Typen]]

## Integer
### Size and Range
- 32-bit: **-2,147,483,648** bis **2,147,483,64*7****
- **signed**(`int`)/**unsigned**(`unsigned int`-> **0** bis **4,294,967,295** on 32-bit)
<!--SR:!2024-08-21,4,270-->
### Storage + Memory Allocation
- fixed amount of memory per `int`: typically **4 Bytes**
- default: [[0701 Stack]]
- `int`-Arrays will occupy contiguous memory locations

### Operators and Arithmetic
- Supported:
	- Addition
	- Subtraction
	- Division
	- Multiplication
- **Integer division truncates fractional part**
- bitwise operations are available

### Performance
- most efficient type for integer arithmetic

## Short
### Size and Range
- **-32,768** bis **32,767**
- **signed**(`short`)/**unsigned**(`unsigned short` -> **0** bis **65,535**)
<!--SR:!2024-08-21,4,270-->

### Storage + Memory Allocation
- fixed amount of memory per `short`: typically **2 Bytes**
- default: [[0701 Stack]]
- `short`-Arrays will occupy contiguous memory locations
### Operators and Arithmetic
- Supported:
	- Addition
	- Subtraction
	- Division
	- Multiplication
- **Integer division truncates fractional part**
- bitwise operations are available
### Performance
- useful to conserve memory
- sometimes slower than [[#Integer]] if the system favors larger data types
## Long
### Size and Range

### Storage + Memory Allocation

### Operators and Arithmetic

### Performance

## Long Long
### Size and Range


### Storage + Memory Allocation

### Operators and Arithmetic

### Performance

## Char
### Size and Range


### Storage + Memory Allocation

### Operators and Arithmetic

### Performance

# Code Beispiele/Aufgaben
## Boolean
```cpp
int main() {
	using namespace std;
	bool a;
	bool b = 42;
	bool c = false;
	bool d = a && b;
	bool e = !d;
	bool f = true;
	if (d && e) {
		f = false;
	}
	cout << boolalpha << a << "\n" << b << "\n" << c << "\n" << d
	<< "\n" << e << "\n" << f << endl;
} // bestimme die Ausgabe des Programms
```

<details>
<summary><b>Solution</b></summary>
- random<br/>
- true<br/>
- false<br/>
- depends on `a` -> unknown<br/>
<!--SR:!2024-08-21,4,270-->
- depends on `d` -> unknown, `!d`<br/>
<!--SR:!2024-08-21,4,270-->
- true(`e` is always `!d`)<br/>
</details>

# Flashcards
