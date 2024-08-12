---
tags:
  - cpp
links:
---

# Unique Pointer
- kann nicht kopiert werden
	-> *als **rvalue** an andere Besitzer uebetragen werden*
- wird automatisch geloescht(`delete`)

# Shared Pointer
- erweitert [[Smart Pointer#Unique Pointer]]
- mehrere Besitzer -> *kopierbar* 
	-> geloescht wenn alle Kopien ausm Scope gehen

# Weak Pointer
- Referenz auf [[Smart Pointer#Shared Pointer|Shared Pointer]] 
- ungueltig wenn shared pointer geloscht/neu zugewiesen wird
- 


# Code Beispiele/Aufgaben


# Flashcards
