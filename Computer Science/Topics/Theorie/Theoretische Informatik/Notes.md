
86 
LOOP := Menge aller LOOP Funktionen


103:
- Falls $x < 1 \Rightarrow f(x) = 0$
- fuer $x > 1$ gilt
	- innere While
		- wirkt wie abrundende division mit 2
	- if
		- testet ungerade
			- wurde zugewiesen rundet?
			- = war $x_{neu}$ ungerade => x = 6\*x + 4 zugewiesen
	- aeussere Schleife
		- Falls x gerade => x/2
		- sonst => x = 3\*x+1 (\*)
f(a):
	- 0 falls a >= 1
	- 0 falls a > 1 und (x) zu x = 1 fuehrt
	- sonst n.d.
Gilt f(a) = 0 fuer alle $x \in \mathbb{Z}$?
Vermutung: ja - wurde aber noch nicht bewiesen/widerlegt

>Collatz Problem v. 1937

Fazit: Es kann schwierig sein, die von einem Programm berechnete Funktion zu bestimmen.
Insbesondere die Equivalence von Programmen ist schwer zu testen => ist f(a) zu g(x) = 0 äquivalent 


$$
f_3(x) = \sum_{i=0}^xx
$$


## Registermaschinen
119
