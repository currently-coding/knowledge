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
