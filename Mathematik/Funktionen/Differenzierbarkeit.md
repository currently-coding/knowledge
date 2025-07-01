>[!Card] Differentialquotient
>Differentialquotient einer Funktion $f$ an der Stelle $x_{0}$ := $$\lim_\limits{ h \to 0 } \frac{f(x_{0}+h) - f(x_{0})}{h}$$
<!--SR:!2025-09-09,70,294-->


>[!Definition] Wann ist eine Funktion an der Stelle $x_{0}$ differenzierbar?
>Existiert für eine Funktion $f$ an der Stelle $x_{0}$ der Differentialquotient $\lim_\limits{ h \to 0 } \frac{(x_{0}+h) - f(x_{0})}{h}$, so heißt $f$ an der Stelle $x_{0}$ differenzierbar.
<!--SR:!2025-06-04,20,270-->

>[!Definition] Wann ist eine Funktion in einem Intervall $I$ differenzierbar?
>Ist eine Funktion $f$ für alle Werte eines Intervalls $I$ differenzierbar, so nennt man $f$ eine in $I$ differenzierbare Funktion.
<!--SR:!2025-06-05,21,270-->

## Beispiele
### $f$ nicht Differenzierbar in $x \in \mathbb{D}_{f}$
```desmos-graph
y = \left\{ x<0:-x, x>=0:x \right\}  
y = x^{1/3}  
y = \left\{ x<0:-1, x=0:0, x>0:1 \right\}  
```
### $f$ differenzierbar in $x \in \mathbb{D}_{f}$
```desmos-graph
y = x^3  
y = \sin(x)  
y = e^x  
```

