>[!Card] Gebrochen-rationale Funktion
>Eine gebrochen rationale Funktion kann in der Form $x \mapsto \frac{p(x)}{q(x)}$ mit ${} q$ und $p$ als Polynom dargestellt werden, wobei $q(x)$ min. Grad 1 hat.
<!--SR:!2025-07-19,8,250-->

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
- gegeben sei $f: \mathbb{R} \rightarrow \mathbb{R}$ mit $f(x) = \frac{5x^2-7}{x^2-x}$. Berechne alle Nullstellen.
 *Graph*
```desmos-graph
y=(5x^2-7)/(x^2-x)
```
*Lösung*
$5x^2-7=0$
$5x^2=7$
$x^2=\frac{7}{5}$
$x=\sqrt{\frac{7}{5} }$
$x_1=+1.4$
$x_{2}=-1.4$

## Definitionslücken
>[!Card] Definitionslücken
>Sei $f: \mathbb{A} \rightarrow \mathbb{B}$ mit $D_{f}$ als Definitionsmenge. Dann ist $\mathbb{L} = \mathbb{A}-D_{f}$  die Menge aller Definitionslücken.
<!--SR:!2025-07-20,9,250-->

$f(x)=\frac{p(x)}{q(x)}=n.d \implies$ für $q(x)=0$ ist $f(x)$ undefiniert.
- Wann treten Definitionslücken auf?
	- Division mit $0$
	- negative Wurzeln
	- Logarithmen mit negativem Argument
### Beispiel
- gegeben sei $f: \mathbb{R} \rightarrow \mathbb{R}$ mit $f(x) = \frac{x^3+5x^2-7}{x^2-x}$. Berechne alle Definitionslücken.
*Lösung*
$x^2-x=0$
$x(x-1)=0$
$x_{1}=0$
$x_{2}=1$
## Grenzwert
- Der Grenzwert einer gebrochen-rationalen Funktion ist sein **Leitkoeffizient**
- Leitkoeffizient = $\frac{\text{Koeffizient der hoechsten Potenz in }p(x)}{\text{Koeffizient der hoechsten Potenz in }q(x)}$
### Graphen
```desmos-graph
y=(x^2+1)/(x^3+1)
y=(x^3+1)/(x^2+1)
y=(x^3+1)/(x^2-1)|dotted
y=(x^5-1)/(x^3+1)
```
### Leitpotenz des Zählers < Leitpotenz des Nenners
 $\Rightarrow$ Graph verläuft gegen $0$
 $f(x)=\frac{x^3+1}{x^7-1} \implies\lim_\limits{ x \to \infty }f(x)=0$
```desmos-graph
 right=5; left=-5;
 top=5; bottom=-5;
 ---
y=(x^3+1)/(x^7-1)
```
### Leitpotenz des Zählers > Leitpotenz des Nenners
$\Rightarrow$ Graph verläuft gegen $\pm \infty$
$f(x)=\frac{x^{3}}{x^{-1}}     \implies \lim_\limits{ x \to \infty }f(x)= \pm \infty$
```desmos-graph
right=20;left=-20;
bottom=-20; top=20;
---
y=(x^3)/(x+1)
```
### Leitpotenz des Zählers = Leitpotenz des Nenner
$\implies$ Graph verläuft gegen Leitkoeffizient
$f(x)=\frac{x^5+2}{x^5-10}\implies \lim_\limits{ x \to  \pm\infty }f (x)=1$
```desmos-graph
 right=5; left=-5;
 top=5; bottom=-5;
 ---
y=(x^5+2)/(x^5-10)
```
### Sonderfälle
#### Leitpotenz des Zählers = Leitpotenz des Nenners + 1
$\implies$ hat eine Asymptote der Form $mx+t$
 $f(x)=\frac{x^{5}-1}{x^{4}+1}     \implies \lim_\limits{ n \to \infty }f(x)=\pm \infty$
 ```desmos-graph
 right=5; left=-5;
 top=5; bottom=-5;
 ---
 y=(x^5-1)/(x^4-1)
```
$f(x)=\frac{x^{5}-1}{x^{4}+1} \implies \lim_\limits{ x \to \infty }f(x)=\pm \infty$
 ```desmos-graph
 right=5; left=-5;
 top=5; bottom=-5;
 ---
 y=(x^5-1)/(x^4+1)
```