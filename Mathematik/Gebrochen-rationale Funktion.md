>[!Definition]
>Eine gebrochen rationale Funktion kann in der Form $x \mapsto \frac{p(x)}{q(x)}$ mit ${} q$ und $p$ als Polynom dargestellt werden, wobei $q(x)$ min. Grad 1 hat.

## Graph
```desmos-graph
left=-20; right=20;
top=20; bottom=-20;
---
y=(x^3+2)/(x)
y=10/x
y=(x^2)/(x+2)
y=(x^3+2x^2+x+5)/(x^5+2)
```
## Nullstellen
$$f(x)=0 \implies p(x)=0, \text{da } \frac{a}{b}=0 \text{ fuer }a=0$$
### Beispiel
- gegeben sei $f: \mathbb{R} \rightarrow \mathbb{R}$ mit $f(x) = \frac{x^3+5x^2-7}{x^2-x}$. Berechne alle Nullstellen.
 Graph:
```desmos-graph
y=(x^3+5x^2-7)/(x^2-x)
```
Loesung:
$x^3+5x^2-7=0$
$x^3+5x^2=7$
$x^2(x+5)=7$

## Definitionslücken
>[!Definition]
>Sei $f: \mathbb{R} \rightarrow \mathbb{R}$ mit $D_{f}$ als Definitionsmenge. Dann ist $\mathbb{L} = \mathbb{N}-D_{f}$  die Menge aller Definitionslücken.

$f(x)=\frac{p(x)}{q(x)}=n.d \implies$ für $q(x)=0$ ist $f(x)$ undefiniert.
- Wann treten Definitionslücken auf?
	- Division mit $0$
	- negative Wurzeln
	- Logarithmen mit negativem Argument

## Grenzwert
- Der Grenzwert einer gebrochen-rationalen Funktion ist sein **Leitkoeffizient**
- Leitkoeffizient = $\frac{\text{Koeffizient der hoechsten Potenz in }p(x)}{\text{Koeffizient der hoechsten Potenz in }q(x)}$
### Beispiel
- gegeben sei $f: \mathbb{R} \rightarrow \mathbb{R}$ mit $f(x) = \frac{x^3+5x^2-7}{x^2-x}$. Berechne alle Definitionslücken.
- 