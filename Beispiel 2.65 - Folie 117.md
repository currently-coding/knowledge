 Eingabe: x, y

- Schleife Zeilen 1-4: => 4 Schritte pro Durchlauf
	- wird genau \[R1] = y mal durchlaufen
- 4 weitere Schritte durch Zeilen 0, 1, 5, 6
-> $t_M(x, y) = 4 \cdot y + 4 \leq 4 \cdot (2^{|y|+1}-2) +4\leq 4 \cdot 2^{|y| + 1} \leq 8 \cdot 2^{|x| + |y|} = 8 \cdot 2^n$
- $n = |x| + |y|$ => RAM berechnet in der Zeit $O(2^n)$
