
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

>Collatz Problem v. 1937