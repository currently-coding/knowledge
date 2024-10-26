---
tags:
  - cpp
links:
---
# Generell
- `char*` mit `std::string` kompatibel
- per se als `immutable` gedacht -> Funktionen geben neuen String zurück
<!--SR:!2024-08-21,4,272-->

## Funktionen
![[Pasted image 20240503120733.png]]
- `hello.substr(3, 6)` -> Start `3`, Länge `6` => von `3` bis `9`
<!--SR:!2024-08-21,4,272-->
- `>`/`<` Operatoren rufen `<string>.compare(<string>)` auf
# Code Beispiele/Aufgaben
![[Pasted image 20240503120622.png]]

# Flashcards
- Lies einen `int` von einem `string` ;; `stoi(string)`

<!--SR:!2024-09-03,17,290-->
- Lies einen `double` von einem `string` ;; `stod(string)`

<!--SR:!2024-08-31,14,290-->
- Konvertiere eine Zahl zu einem `string` ;; `to_string(`

<!--SR:!2024-08-20,3,250-->
