264: 0, 01, 011, ... $= L(01^*)=L(0+01^*)$
$$

$$


266:

$A = \{w \in \{0, 1\}^*$ in $w$ kommen nie zwei 0 oder 1 hintereinander vor $\}$
$\alpha = (01)^* + (10)^* + 0(10)^* + 1(01)^*$
- $\epsilon$ in $(01)^*$ bereits enthalten
es gilt $L(\alpha) = A$
$\alpha$ kann noch verkürzt werden:
$\alpha' = (\epsilon + 1)(01)^*(\epsilon + 0)$
=> Es gilt $L(\alpha') = A$

![[3.27]]

[[3.32 - NFA zu reg. Ausdruck]]

Pumping Lemma:
Beweis:
- Sei $L \in REG \implies$ nach 3.28 es existiert $DFA = (\sum, S, \delta, s_0, F)$ mit $L(A) = L$
- Wir wählen ${} k = |S| {}$ und zeigen, dass $L$ 3-pumpbar ist
<!--SR:!2025-01-10,16,290-->
- Sei $w \in L$ mit $|w| \geq k$ 
- Also $w = a_1 a_2 ....a_m$ mit $m \geq k$ und $a_1, a_2, ..., a_m \in \sum$
- Für $0 \leq i \leq k$ definieren wir $q_i = \bar{\delta}(s_0, a_1a_2...a_m)$
	- $q_i$ ist der Zustand nach dem i-ten Zeichen von $w$
- $q_0, ..., q_k \in S$ sind $k+1$ Zustände
=> aus $|S| < k+1$ folgt, dass min. zwei der $q_0, ..., q_k$ gleich sind
d.h. es existiert $i, j$ mit $0 \leq i \lt j \leq k$ und $q_i = q_j$
- -> zwischen $i$ und $j$ wurde einmal im Kreis gelaufen
$x = a_1 ... a_i$
$y = a_{i+1}...a_j$
$z = a_{j+1}...a_m$


Damit gilt:
1. $w = xyz$
2. $y \neq \epsilon$ (weil $i \lt j$)
3. $|xy| = j \leq k$
4. Es gilt $\forall_{r \geq 0} xy^r z \in L$ ,denn 
	1. $\bar{\delta}(s_0, x) = \bar{\delta}(s_0, a_1 ... a_i) = q_i$
	2. $\bar{\delta}(q_i, y) = \bar{\delta}(s_0, xy) = \bar{\delta}(s_0, a_1...a_j) = q_j = q_i$
	3. $\bar{\delta}(q_i, z) = \bar{\delta}(q_j, z) =\bar{\delta}(s_0, xyz) = \bar{\delta}(s_0, w)$
für $r \geq 0$ gilt also:
$\bar{\delta}(s_0, xy^rz) =(a) \bar{\delta}(q_i, y^rz) = \bar{\delta}(q_i, y^{r-1}z) =(b) \bar{\delta}(q_i, y^{r-2}z) =(b) ... = (b)\bar{\delta}(q_i, z) \in(c) FA$
=> $xy^r z \in L$
$\square$





- Potenzmengenkonstruktion  fure NFA -> DFA beachten:
	- jeder Zustand des DFAs muss ausgehende Pfeile fure alle moelgichen Eingaben haben








































