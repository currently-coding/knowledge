## Basic
- Bracketing mathematical expressions: $\lparen \rparen$, $\brack$
- Function Arguments: $\lparen \rparen$
- Bracketing [[#Sets]]: $\brace$


>[!Note]
>0 is a **natural** number $0 \in \N$
>
## Sets
$$
\begin{align*}
A \cap B := & \{a \mid a \in A \text{ and } a \in B\} \quad \text{(Intersection of A and B)} \\
A \cup B := & \{a \mid a \in A \text{ or } a \in B\} \quad \text{(Union of A and B)} \\
A \setminus B := & \{a \mid a \in A \text{ and } a \notin B\} \quad \text{(Difference of A and B)} \\
A - B := & A \setminus B \quad \text{(Difference of A and B)} \\
A := & M \setminus A \quad \text{(Complement of A relative to a fixed base set M)} \\
P(A) := & \{B \mid B \subseteq A\} \quad \text{(Power set of A)} \\
\#A = |A| := & \text{number of elements of a finite set A}
\end{align*}

$$

- powersets
### Set Operations

## Tuple(Vector)

### Cartesian Product

## Quantifiers

## Functions
$$
\begin{align*}
g \circ f &: \text{denotes the function } A \to C \text{ with } (g \circ f)(x) \stackrel{\mathrm{df}}{=} g(f(x)) \quad \text{(Composition of functions)} \\
Df \stackrel{\mathrm{df}}{=} & \{a \in A \mid \exists b \in B, f(a) = b\} \quad \text{(Domain of definition of } f\text{)} \\
Rf \stackrel{\mathrm{df}}{=} & \{b \in B \mid \exists a \in A, f(a) = b\} \quad \text{(Range of } f\text{)} \\
f \text{ is total} \stackrel{\mathrm{df}}{\Leftrightarrow} & Df = A \\
f \text{ is surjective} \stackrel{\mathrm{df}}{\Leftrightarrow} & Rf = B \\
f \text{ is injective} \stackrel{\mathrm{df}}{\Leftrightarrow} & f(a_1) \neq f(a_2) \quad \text{for all distinct } a_1, a_2 \in Df \\
f \text{ is bijective} \stackrel{\mathrm{df}}{\Leftrightarrow} & f \text{ is total, surjective, and injective} \\
f^{-1} &: \text{If } f \text{ is injective, there exists the inverse function } f^{-1}: B \to A \\
f^{-1}(b) \stackrel{\mathrm{df}}{=} & \text{the } a \in A \text{ with } f(a) = b \\
\text{Note:} & \quad f^{-1}(f(a)) = a \quad \text{for } a \in Df \\
& \quad f(f^{-1}(b)) = b \quad \text{for } b \in Rf
\end{align*}
$$
- Bild: Pfeile zwischen Mengen 
- inverse Funktion nur von injekive Funktionen zu bilden( da sonst ein x zwei y abbildet)

## C