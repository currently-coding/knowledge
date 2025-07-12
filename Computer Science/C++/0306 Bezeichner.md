---
tags:
  - cpp
links:
---
## Generell
- geben Entitäten wie [[0406 Datentypen|Objekten]], [[0501 Objekte|Objekten]] und [[0309 Funktionen|Funktionen]] Namen
- Geltungsbereich eines Bezeichners durch seinen **Kontext** festgelegt(Block, Funktion, Datei)
## Erlaubt/Nicht Erlaubt
- erlaubte Zeichen
	- \[A-Za-z_]
	- \[A-Za-z0-9_]
- *nicht* erlaubt: [[0302 Schlüsselwörter]]
- *soll nicht* verwendet werden: `_`(nur für besondere [[Entitäten]])

## Konvention
| Name               | Verwendung                      |
| ------------------ | ------------------------------- |
| `camelCase`        | Funktionen                      |
| `PascalCase`       | Datentypen                      |
| `snake_case`       | Funktionen + Datentypen         |
| `UPPER_SNAKE_CASE` | Konstanten + Template Parameter |
| `kebap-case`       | nicht möglich                   |
### Private Bezeichner
| Name       | Verwenung           |
| ---------- | ------------------- |
| `m_<name>` | Klassen und Objekte |
| `<name>_`  | Klassen und Objekte |

## Flashcards