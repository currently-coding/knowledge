## Inhalt
- [Karteikarten](#Karteikarten)
- **[Installation](#installation)**
- [Shortcuts](#Hotkeys)

### Karteikarten

Aufbau:
```
<Vorderseite der Karteikarte> <Trennzeichen> <Rückseite der Karteikarte>
```

Dazwischen dürfen beliebig viele Leerzeichen sein.
Die Trennzeichen hierbei sind:
- -> für unidirektionelle Karteikarten
- <-> für bidirektionelle Karteikarten

Beispiel:
H <-> Wasserstoff


### Links vs Tags - Was wann verwenden
#### Links
- um mehr Informationen zu einem Thema anzugeben
-> Links in den Notizen verwenden
```markdown
...Oxidation von [[0332 Alkohole|Alkoholen]]...
```
##### Links erstellen
- `[[<Dateiname>|<Name der im Text erscheinen soll>]]` -> verlinkt gesamte Notiz
- `[[<Dateiname>#<Überschrift>|<Name der im Text erscheinen soll>]]` -> Verlinkt direkt zu Überschrift

#### Tags
- um Notizen später gruppieren zu können
	- schnelles Suchen von Themen
-> Tags in den `tags` Abschnitt unter der Überschrift reinschreiben(min. Fachnamen)


## Installation
- Voraussetzungen
  - `Git` installiert -> [Git Downloads](https://git-scm.com/downloads)
  - `Obsidian` installiert -> [Obsidian Downloads](https://obsidian.md/download)
  - `API Token` erhalten -> Bei mir nachfragen

1. Klone das `git` repository
   1. Bereite einen Link in diesem Format vor:
      `https://<API Token>@github.com/<username>/<repository>.git`\
      `https://<API Token>@github.com/currently-coding/school.git`
   2. `git clone <link>` in CMD/Terminal/Console ausführen

2. Öffne `Obsidian`
   1. Wähle `open` aus, um einen Ordner als Vault zu öffnen
      1. Falls sich bereits ein Vault öffnet/dieses Menü nicht sichtbar ist `<ctrl\> + p` drücken und `open another vault` eingeben und auswählen
   2. Den gerade durch das Klonen erstellten Ordner auswählen
   3. `Trust author and enable plugins` auswählen
      1. Falls eine Fehlermeldung erscheint, dass `ExcaliBrain Disabled` ist, `Obsidian neu starten`

3. Git Plugin einrichten
   1. `<ctrl> + ,`
   2. `community plugins` auswählen
   3. Unter `Installed Plugins` `Git` auswählen, indem man auf das Zahnrad (`Options`) drückt
   4. **WICHTIG**: Einstellungen unter `Automatic` nicht verändern, außer man ist sich den Veränderungen bewusst
   5. Unter `Commit Message` -> `{{hostname}} placeholder replacement` bitte Initialen eingeben. (Verwendet, um nachvollziehen zu können, wer Veränderungen gemacht hat)
   6. Unter `Commit Author` -> `Author Name for commit` ebenfalls Initialen eingeben
   7. Unter `Commit Author` -> `Author email for commit` eine valide E-Mail Adresse hinterlegen

Obsidian ist nun vollständig eingerichtet und wird automatisch alle 5 Minuten den lokalen Stand auf github.com/currently-coding/school hochladen und den dortigen Stand ergänzen.
