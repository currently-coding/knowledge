---
tags:
  - c
links: "[[00 C]]"
---
## Anwendungssituation
- Speichern von Werten

## Wie funktionierts ?
- Deklaration -> Definition -> Initialisierung => Verwendung der Variable
<!--SR:!2024-08-21,4,286-->
- Definition und Deklaration passiert in C gleichzeitig
```C
# // Deklaration
int num;

// Definition
num;

// Initialisierung
num = 10;

// Deklaration und Definition
int num;

// Deklaration, Defintion und Initialisierung
int num = 10;
```
### Scopes
#### Global
- im gesamten Programm sichtbar
- Speicherplatz wird nach Beenden des Programms freigegeben
#### Lokal
- innerhalb des derzeitigen Code-Blocks(meist Funktion)
- Speicherplatz wird beim Verlassen freigegeben

## Code Beispiele/Aufgaben
```c
int main() {
    // Declaration, Definition, and Initialization
    int num = 10; 

    printf("The value of num is: %d\n", num);
    return 0;
}
```

## Flashcards
Deklaration:::Spezifizieren des Datentypes und Variablennamens. Dadurch erfährt der Compiler von der Existenz der Variable. Speicher wird **nicht** reserviert


<!--SR:!2025-06-10,297,310-->
Definition:::Der Compiler allokiert Speicher für die Variable


<!--SR:!2025-01-24,160,310-->
Initialisierung:::Der Variable wird ein initialer Wert zugewiesen


<!--SR:!2025-03-23,218,330-->
Reihenfolge der Schritte beim Erstellen einer Variable::Deklaration -> Definition -> Initialisierung
<!--SR:!2025-02-09,176,310-->
