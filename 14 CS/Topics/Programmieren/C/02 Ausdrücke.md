---
tags: 
links: "[[00 C]]"
---
## Anwendungssituation
- Ausdrücke werden berechnet oft einer Variable zugewiesen
## Wie funktionierts ?
- werden im umgebende Kontext verwendet(z.B. rechte Seite einer Zuweisung)
- haben einen statischen Wert, der vom Compiler berechnet wird
## Code Beispiele/Aufgaben
```C
int num = 1 + 2;

int add(int a, int b) {
	return a + b;
}

int result = add(3, 4);
```

## Flashcards
- Wann werden Ausdruecke berechnet::Beim compilen
- Ist der Wert eines Ausdrucks statisch::Ja
- 
