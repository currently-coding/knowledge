---
tags:
  - cpp
links:
---
# Stream Typhierarchie(Vererbung)
![[Pasted image 20240503122001.png]]
- [[0520 Vererbung]]
## Output Stream
- `std::cout` Objekt vom Typ `ostream`
![[Pasted image 20240503121351.png]]
All in STL: `std`
- `cout` Standardausgabe(*gepuffert* -> evtl. keine Ausgabe bei Crash nach Befehl)
<!--SR:!2024-08-21,4,272-->
- `cerr` Standardfehlerausgabe(*ungepuffert* -> direkte Ausgabe)
<!--SR:!2024-08-21,4,272-->
- `clog` Standardfehlerausgabe(*gepuffert*)
- `flush` leert *Puffer* und schreibt Ausgabe
- `endl` newline + `flush`

<!--SR:!2024-08-31,14,290-->
![[Pasted image 20240503121657.png]]

## Input Stream
- `cin` Objekt vom Typ `std::istream`
- `<<` trennt Eingabe nach Whitespace und weist passen zu
![[Pasted image 20240503121822.png]]
## String Stream
- bezieht sich weder auf Standard Ein/Ausgabe noch [[0830 (Datei)-Ein-Ausgabe|Dateien]]
- vereinfacht Konvertierungen
![[Pasted image 20240503123012.png]]
### Zeilenweises Einlesen von Dateien
- `false` falls keine Zeile mehr
![[Pasted image 20240503123223.png]]
# Stream Manipulation
- `#include <iomanip>`
- `stream manipulatoren` werden per `<<`/`>>` übergeben
- steuern Einlese- und Ausgabeverhalten
- bleiben aktiv bis sie aktive deaktiviert werden
---
![[Pasted image 20240503123753.png]]
- - -
- `noskipws` -> Whitespace als input
<!--SR:!2024-08-21,4,272-->
# Code Beispiele/Aufgaben
![[Pasted image 20240503121845.png]]
![[Pasted image 20240503121657.png]]
# Flashcards
