## $\bar{L}$
- Sei $L = L(A)$ mit **DFA** $A = (\sum, S, \delta, s_0, F)$
=> $\bar{L} = L(A')$ mit $A' = (\sum, S, \delta, s_0, S-F)$
>[!Note]
>nur mit **DFA** moeglich da NFAs auch wenn nicht alle derzeitigen Zustaende akzeptieren, ein Wort akzeptieren koennen. Wechselt man nun alle Zustaende, so wird auch der Situation
### Idee
- alle akzeptierenden und nicht-akzeptierenden States vertauschen($F' = S-F$)

## $L \cup L$
$L = L(A_1)$ mit $A_1 = (\sum, S_1, \delta, s_{10}, F_1)$
$L' = L(A_2)$ mit $A_2 = (\sum, S_2, \delta, s_{20}, F_2)$
wobei $A_1$ und $A_2$ **NFAs** sind mit $S_1 \cap S_2 = \emptyset$.
konstruieren NFA $A = (\sum, S, \delta, s_0, F)$ mit $L(A)= L \cup L'$

$S:=S_1 \cup S_2 \cup \{s_0\}$ wobei $s_0 \notin S_1 \cup S_2$
$\delta(s, a) := \begin{cases} \delta_1(s, a), \text{ falls } s \in S_1 \\ \delta_2(s, a), \text{ falls }  s \in S_2 \\ \delta_1(s_{10}, a) \cup \delta_2(s_{20}, a), \text{ falls }s = s_0 \end{cases}$
$F := \begin{cases} F_1 \cup F_2, \text{ falls } s_{10} \notin F_1 \text{ und } s_{20} \notin F_2\\F_1 \cup F_2 \cup \{s_0\}, \text{ sonst} \end{cases}$
Damit gilt $L(A) = L(A_1) \cup L(A_2) = L \cup L'$

## $L \cap L'$
- Wir verwenden die De Morgan'schen Regeln
$$L \cap L' = \bar{\bar{L} \cup \bar{L'}}$$
- wegen #todo sind $\bar{L}, \bar{L'} \in FA$
- wegen #todo sind $\bar{L} \cup \bar{L'} \in FA$
- wegen #todo sind $\bar{\bar{L} \cup \bar{L'}} \in FA$

## $L \cdot L'$
$L=L(A_1)$ mit $A_1 = (\sum, S_1, \delta_1, s_{10}, F_1)$
$L'=L(A_2)$ mit $A_2 = (\sum, S_2, \delta_2, s_{20}, F_2)$
- beides sind **NFAs** mit $S_1 \cap S_2 = \emptyset$
### Idee
- von alle akzeptierenden Zustaenden in $A_1$ in, dem startzustand von $A_2$ folgende Zustaende
- Dabei werden alle Akzeptierenden Zustaende von $A_1$ nicht akzeptierend
	- Ausnahme: $s_20$ von $A_2$ ist akzeptierend -> alle akzeptierenden in $A_1$ bleiben akzeptierend

wir konstruieren einen NFA $A = (\sum, S, \delta, s_0, F)$ mit $L(A) = L \cdot L'$
$S = S_1 \cup S_2$
$\delta(s, a) = \begin{cases} \delta_1(s, a), \text{ falls } s \in S_1 - F_1 \\ \delta_1(s, a) \cup \delta_2(s, a), \text{ falls }s \in F_1 \\ \delta_2(s, a), \text{ falls } s \in S_2 \end{cases}$
$s_0 = s_10$
$F= \begin{cases} F_2, \text{ falls } s_{20} \notin F_2 \\ F_1 \cup F_2, \text{ falls }s_{20} \in F_2 \end{cases}$
=> $L(A) = L \cdot L'$

## $L^*$
$L = L(A_1)$ mit NFA $A_1 = (\sum, S_1, \delta_1, s_{10}, F_1)$
wir konstruieren NFA $A = (\sum, S, \delta, s_0, F)$ mit $L(A) = L^*$

$S := S_1 \cup \{s_0\}$ mit $s_0 \notin S_1$
$\delta(s, a) = \begin{cases} \delta_1(s_{10}, a), \text{ falls }s=s_0\\\delta_1(s_{}, a), \text{ falls } s\in S_1-F_1\\\delta_1(s, a) \cup \delta_1(s_{10}, a), \text{ falls } s\in F_1\end{cases}$
- letzte Zeile: falls $s \in F_1$: in alle Zustände, in die man von $s$ aus gegangen wäre und alle in die man von $s_{10}$ gegangen wäre
$F=F_1 \cup \{s_0\}$
=> $L(A) = L^*$
