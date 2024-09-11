# README

## Inhalt
- [Karteikarten](#karteikarten)
- [Links vs Tags](#links-vs-tags---was-wann-verwenden)
- [Installation](#installation)

---

## Karteikarten

### Aufbau:
```
<Vorderseite der Karteikarte> <Trennzeichen> <Rückseite der Karteikarte>
```

Zwischen den Einträgen können beliebig viele Leerzeichen stehen. Die Trennzeichen sind:
- `->` für unidirektionale Karteikarten
- `<->` für bidirektionale Karteikarten

#### Beispiel:
- **Unidirektional:** `H -> Wasserstoff`
- **Bidirektional:** `H <-> Wasserstoff`

---

## Links vs Tags - Wann was verwenden

### Links
Links werden verwendet, um mehr Informationen zu einem Thema zu verknüpfen.

#### Syntax für Links:
- `[[<Dateiname>|<Text, der angezeigt werden soll>]]` -> Verlinkt die gesamte Notiz.
- `[[<Dateiname>#<Überschrift>|<Text, der angezeigt werden soll>]]` -> Verlinkt direkt zu einer bestimmten Überschrift innerhalb der Notiz.

#### Beispiel:
```markdown
...Oxidation von [[0332 Alkohole|Alkoholen]]...
```

---
## Installation

### Voraussetzungen:
- **Git** installiert -> [Git Downloads](https://git-scm.com/downloads)
- **Obsidian** installiert -> [Obsidian Downloads](https://obsidian.md/download)
- **API Token** erhalten -> Bei mir nachfragen

### Anleitung:
1. **Repository klonen**
   1. Bereite den Link im folgenden Format vor:  
      `https://<API Token>@github.com/<username>/<repository>.git`  
      Beispiel: `https://<API Token>@github.com/currently-coding/school.git`
   2. Führe in der Konsole folgenden Befehl aus:  
      `git clone <link>`

2. **Obsidian öffnen**
   1. Wähle `open`, um einen Ordner als Vault zu öffnen.
      - Falls bereits ein Vault geöffnet ist, `<Ctrl> + P` drücken und `open another vault` auswählen.
   2. Wähle den zuvor geklonten Ordner aus.
   3. Bestätige mit `Trust author and enable plugins`.
      - Falls eine Fehlermeldung (`ExcaliBrain Disabled`) erscheint, Obsidian neu starten.

3. **Git Plugin einrichten**
   1. Drücke `<Ctrl> + ,`, um die Einstellungen zu öffnen.
   2. Wähle `community plugins`.
   3. Unter `Installed Plugins` das `Git` Plugin auswählen und das Zahnrad (`Options`) öffnen.
   4. **Wichtig:** Die Einstellungen unter `Automatic` nicht ändern, außer die Auswirkungen sind bekannt.
   5. Unter `Commit Message -> {{hostname}} placeholder replacement` die Initialen eintragen.
   6. Unter `Commit Author -> Author Name for commit` und `Author email for commit` eine E-Mail-Adresse hinterlegen.

Obsidian ist jetzt vollständig eingerichtet und synchronisiert alle 5 Minuten automatisch den lokalen Stand mit `github.com/currently-coding/school`.
