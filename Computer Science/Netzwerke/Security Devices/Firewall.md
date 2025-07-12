## Allgemeines
- kann in [[Router|Routern]], [[Host|Hosts]] oder auf einem eigenen Gerät platziert werden
- arbeitet in mehreren [[Computer Science/Netzwerke/OSI Model/OSI Model|OSI]] Layern: 2,3,4,7
- Schützt internes Netz vor Angriffen von außen

## Funktionsweise
- hindert [[Paket|Pakete]] am Eintreten und Verlassen eines [[Netzwerk|Netzwerks]]
### Stateless Inspection
- überprüft jedes [[Paket]]
-> falls eine Regel auf dieses zutrifft, so wird die dazugehörige Konsequenz ausgeführt
### Stateful Inspection
- überprüft den Status der Verbindung zwischen Netzwerken
- erlaubt oder verbietet dann bestimmte Verbindungen
	- Bsp.: es dürfen keine externen Verbindungen mit dem internen Netzwerk geschlossen werden