# README

## Installation

### Voraussetzungen:
- **Git** installiert -> [Git Downloads](https://git-scm.com/downloads)
- **Obsidian** installiert -> [Obsidian Downloads](https://obsidian.md/download)
- Für schreibenden Zugriff: **API Token**

### Anleitung:
1. **Repository klonen**
   1. Bereite den Link im folgenden Format vor:  
      `https://<API Token>@github.com/<username>/<repository>.git`  
      Beispiel: `https://<API Token>@github.com/currently-coding/school.git`
   2. Führe in der Konsole(evtl. in `Git Bash`) folgenden Befehl aus:  
      `git clone <link>`

2. **Obsidian öffnen**
   1. Wähle `open`, um einen Ordner als Vault zu öffnen.
      - Falls bereits ein Vault geöffnet ist, `<Ctrl> + P` drücken und `open another vault` auswählen.
   2. Wähle den zuvor geklonten Ordner aus.
   3. Bestätige mit `Trust author and enable plugins`.
3. Die Einrichtung des lesenden Zugriffs ist nun abgeschlossen. Der Vault wird sich automatisch updaten(alle 5min) und immer die neueste Version von Dateien beinhalten.


4. **Git Plugin einrichten**(nur für schreibenden Zugriff)
   1. Drücke `<Ctrl> + ,`, um die Einstellungen zu öffnen.
   2. Wähle `community plugins`.
   3. Unter `Installed Plugins` das `Git` Plugin auswählen
   4. **Wichtig:** Die Einstellungen unter `Automatic` nicht ändern, außer die Auswirkungen sind bekannt.
   5. Unter `Commit Message -> {{hostname}} placeholder replacement` die Initialen eintragen.
   6. Unter `Commit Author -> Author Name for commit` und `Author email for commit` eine E-Mail-Adresse hinterlegen.

Obsidian ist jetzt vollständig(schreibend und lesend) eingerichtet und synchronisiert alle 5 Minuten automatisch den lokalen Stand mit `github.com/currently-coding/school`.
