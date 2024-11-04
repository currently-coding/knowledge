Eingabe: x, y $\in \mathbb{Z}$ 
Laufzeit: 
- For Schleife
	- x Schleifendurchlaeufe mit je 2 Rechenschritten
	- 0 Schritte fuer Berechnung der Grenzen(0, x)(weil 0 und x elementare ausdruecke sind)
- max. 7 schritte ausserhalb
=> $t_m(x, y) \leq 2x - 7 \leq 2 \cdot (2^{|x| + 1} - 2) + 7 \leq 4 \cdot (2^{|x| + 1}-2)+7 \leq 4 \cdot 2^{|x| + 1} \leq 8 \cdot 2^{|x| + |y|} = 8 \cdot 2^n$
- $n = |x| + |y|$
=> While Program berechnet das Produkt in der Zeit $O(2^n)$

