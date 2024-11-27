264: 0, 01, 011, ... ${} = L(01^*)=L(0+01^*)$


266:

$A = \{w \in \{0, 1\}^*$ in $w$ kommen nie zwei 0 oder 1 hintereinander vor $\}$
$\alpha = (01)^* + (10)^* + 0(10)^* + 1(01)^*$
- $\epsilon$ in $(01)^*$ bereits enthalten
es gilt $L(\alpha) = A$
$\alpha$ kann noch verkürzt werden:
$\alpha' = (\epsilon + 1)(01)^*(\epsilon + 0)$
=> Es gilt $L(\alpha') = A$

Theorem 3.27: $REG \subseteq FA$
Beweis: Induktion ueber den Aufbau reg. Ausdruecke
 (BC):
 - $L(\emptyset) = \emptyset$ wird akzeptiert durch NFA durch `->s_0`
 - $L(\epsilon) = \epsilon$ wird akzeptiert durch NFA mit finalem und einzigem startzustand
 - $L(a) = a$ mit $a \in \sum$ `->s_0: a-> s_1(akz.)`
(IS):
- Seien $\alpha, \beta$ reg. Ausdrücke
- $L(\alpha + \beta) = L(\alpha) \cup L(\beta)$ ( $\in FA$ nach IV und V in 3.21)
- $L(\alpha \beta) = L(\alpha) L(\beta)$ ($\in FA$ wegen 3.21
- $L(a^*) = L(\alpha)^*$ wegen 3.21

Beispiel 3.28:
NFA für $(ab^* + a)^*$
#todo 
a: -> :a -> akz.
b: -> :b -> akz.
b*: -> akz. :b -> s_1 :b -> s_1; s_2 :b -> s_1
ab*: nach Konstruktion siehe [[3.21 - Concatenation of Languages]]
- von akz. in a nach Folgezustand von start in b + letzten a akz., da b start akz.
ab* + a: nach [[3.21 - Concatenation of Languages]]
- in Folgezustand der jeweiligen Startzustande von neuem Startzustand
(ab* + a)\*:  #todo 3.21 beispiel $L^*$
- neuen akz. Start der in die Folgezustand der anderen start führt
- von allen akz. in folgen des starts gehen


Beispiel 3.32
(eigentlich $\cup$ statt $+$ richtig, aber wir verwenden Syntax reg. Ausdrücke)
1. $L_{s_0} = a \cdot L_{s_0} + b \cdot L_{s_2}{}$
2. $L_{s_1} = (a + b) \cdot L_{s_1} + a \cdot L_{s_0}$
3. $L_{s_2} = a \cdot L_{s_1} + \epsilon$, $\epsilon$ weil leeres Wort von $s_2$ aus akzeptiert wird( -> wenn akz. => $+ \epsilon$)
- Ziel: nach $L_{s_0}$ auflösen

3 in 1 Einsetzen
4. $L_{s_0} = a \cdot L_{s_0} + b \cdot (a \cdot L_{s_1} + \epsilon) = a \cdot L_{s_0} + b \cdot a \cdot L_{s_1} + b (\cdot \epsilon)$

2 Vereinfachen nach Lemma 3.29
5. $L_{s_1} = (a + b)^* \cdot a \cdot L_{s_0}$

5 in 4 Einsetzen
6. $L_{s_0} = a \cdot L_{s_0} + b \cdot a \cdot (a + b)^* \cdot a \cdot L_{s_0} + b$

6 Vereinfachen nach Lemma 3.29
7. $L_{s_0} = (a + ba(a+b)^*a) \cdot L_{s_0} + b$
8. $L_{s_0} = (a + ba(a+b)^*a)^*b$


Pumping Lemma:
Beweis:
- Sei $L \in REG \implies$ nach 3.28 es existiert $DFA = (\sum, S, \delta, s_0, F)$ mit $L(A) = L$
- Wir wählen $k := |S|$ und zeigen, dass $L$ 3-pumpbar ist
- Sei $w \in L$ mit $|w| \geq k$ 
- Also $w = a_1 a_2 ....a_m$ mit $m \geq k$ und $a_1, a_2, ..., a_m \in \sum$
- Für $0 \leq i \leq k$ definieren wir $q_i = \bar{\delta}(s_0, a_1a_2...a_m)$
	- $q_i$ ist der Zustand nach dem i-ten Zeichen von $w$
- $q_0, ..., q_k \in S$ sind $k+1$ Zustaende
=> aus $|S| < k+1$ folgt, dass min. zwei der $q_0, ..., q_k$ gleich sind
d.h. es existiert $i, j$ mit $0 \leq i \lt j \leq k$ und $q_i = q_j$
- -> zwischen $i$ und $j$ wurde einmal im Kreis gelaufen
$x := a_1 ... a_i$    $y := a_{i+1}...a_j$    $z := a_{j+1}...a_m$


Damit gilt:
1. $w = xyz$
2. $y \neq \epsilon$ (weil $i \lt j$)
3. $|xy| = j \leq k$
4. Es gilt $\forall_{r \geq 0} xy^r z \in L$ ,denn 
	1. $\bar{\delta}(s_0, x) = \bar{\delta}(s_0, a_1 ... a_i) = q_i$
	2. $\bar{\delta}(q_i, y) = \bar{\delta}(s_0, xy) = \bar{\delta}(s_0, a_1...a_j) = q_j = q_i$
	3. $\bar{\delta}(q_i, z) = \bar{\delta}(q_j, z) =\bar{\delta}(s_0, xyz) = \bar{\delta}(s_0, w) {}$
für $r \geq 0$ gilt also:
$\bar{\delta}(s_0, xy^rz) =(a) \bar{\delta}(q_i, y^rz) = \bar{\delta}(q_i, y^{r-1}z) =(b) \bar{\delta}(q_i, y^{r-2}z) =(b) ... = (b)\bar{\delta}(q_i, z) \in(c) FA$
=> $xy^r z \in L$
$\square$


