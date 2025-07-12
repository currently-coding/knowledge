---
tags:
  - cpp
links:
---

# Unique Pointer
- kann nicht kopiert werden
	-> *als **rvalue** an andere Besitzer uebetragen werden*
<!--SR:!2024-08-21,4,270-->
- wird automatisch geloescht(`delete`)

# Shared Pointer
- erweitert [[Smart Pointer#Unique Pointer]]
- mehrere Besitzer -> *kopierbar*
<!--SR:!2024-08-21,4,270-->
	-> geloescht wenn alle Kopien ausm Scope gehen
<!--SR:!2024-08-21,4,270-->

# Weak Pointer
- Referenz auf [[Smart Pointer#Shared Pointer|Shared Pointer]] 
- ungueltig wenn shared pointer geloscht/neu zugewiesen wird
- 


# Code Beispiele/Aufgaben


# Flashcards
