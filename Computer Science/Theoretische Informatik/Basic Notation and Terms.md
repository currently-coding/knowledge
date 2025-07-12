## Basic
- Bracketing mathematical expressions: $\lparen \rparen$, $\brack$
- Function Arguments: $\lparen \rparen$
- Bracketing [[#Set|Sets]]: $\brace$

>[!Note]
>0 is a **natural** number $0 \in \mathbb{N}$
>

## Set
### Definition
$\mathbb{N}$ = $\{0, 1, \ldots\}$ (Set of natural numbers)
$\mathbb{N}^+$ = $\{1, 2, \ldots\}$ (Set of positive natural numbers)
$\mathbb{P}$ = $\{2, 3, 5, 7, 11, 13, 17, \ldots\}$ (Set of primes)
$\emptyset$ = empty set
**Important: $0$ is a natural number.**
For $x \in N$, $y \in N^+$ let $(x \mod y)$ = $x - zy$, where $z \in N$ is the greatest number with $zy \leq x$. (just a reminder)

### Element relationship and inclusion
$a \in M$ means $a$ is an element of the set $M$
$a \notin M$ means $a$ is no element of the set $M$
$M \subseteq N$ means for all $a$, if $a \in M$, then $a \in N$
$M \not\subseteq N$ means it does not hold $M \subseteq N$
$M \subsetneq N$ means $M \subseteq N$ and $M \neq N$ (M is proper subset of N)
### Operations
$A \cap B$ := $\{a \mid a \in A \text{ and } a \in B\}$ (Intersection of A and B)
<!--SR:!2025-07-27,161,234-->
$A \cup B$ := $\{a \mid a \in A \text{ or } a \in B\}$ (Union of A and B)
<!--SR:!2025-07-18,205,317-->
$A \setminus B$ oder $A - B$ := $\{a \mid a \in A \text{ and } a \notin B\}$ (Difference of A and B)
<!--SR:!2026-03-03,304,364-->
$A^c$ := $M \setminus A$ (Complement of A relative to a fixed base set M)
<!--SR:!2026-09-29,479,294-->
$P(A)$ := $\{B \mid B \subseteq A\}$ (Power set of A)
<!--SR:!2026-07-11,453,314-->
$\#A$ or $|A|$ ::: number of elements of a finite set A
<!--SR:!2025-06-12,169,310!2024-12-13,46,299-->
## Tuple
$(a_1, a_2, \ldots, a_n)$ := sequence of elements $a_1, a_2, \ldots, a_n$ in this order (n-tuple, n-dimensional vector)
<!--SR:!2025-11-12,291,334-->
### Cartesian Products
$A_1 \times A_2 \times \ldots \times A_n$ := $\{(a_1, a_2, \ldots, a_n) \mid a_i \in A_i \text{ for all } i\}$ (Cartesian product of sets $A_1,A_2, \ldots, A_n$)
<!--SR:!2026-05-04,415,317-->
$A^n$ := $A \times A \times \ldots \times A$ (n-dimensional Cartesian product of set A)
<!--SR:!2027-01-30,578,314-->
The first definition yields the empty tuple $( )$ for $n = 0$. Thus $A^0 = \{( )\}$ and $|A^0| = 1$.
## Quantifiers
$\exists$ = “there exist(s)”
$\forall$ = “for all”
## Functions
### Definition 1.1
$f : A \to B$ is determined by the source set (aka domain) $A$, the target set (aka codomain) $B$, and the graph $G_f \subseteq A \times B$, where for every $a \in A$ there is at most one $b \in B$ with $(a, b) \in G_f$
If $(a, b) \in G_f$, then $f(a)$ = $b$.
If there is no $b \in B$ with $f(a) = b$, then $f(a)$ is not defined (notation: $f(a) = n.d.$).

$g \circ f$ := $f : A \to C$ with $(g \circ f)(x)$ := $g(f(x))$ (composition of functions).
<!--SR:!2026-03-10,376,314-->
$D_f$ := $\{a \in A \mid \exists b \in B \text{ with } f(a) = b\}$ (Domain of definition of f)
<!--SR:!2026-03-09,375,314-->
$R_f$ := $\{b \in B \mid \exists a \in A \text{ with } f(a) = b\}$ (Range of f)
<!--SR:!2026-12-17,581,330-->
$f$ is total ::: $D_f = A$
<!--SR:!2025-07-16,76,294!2026-03-20,397,339-->
$f$ is surjective ::: $R_f = B$
<!--SR:!2025-12-05,285,298!2025-09-13,86,274-->
$f$ is injective ::: $f(a_1) \neq f(a_2)$ for all distinct $a_1, a_2 \in D_f$
<!--SR:!2025-09-16,177,278!2026-05-12,437,314-->
$f$ is bijective ::: $f$ is total, surjective, and injective
<!--SR:!2025-11-29,295,334!2025-11-26,305,338-->
If $f$ is injective, there exists the inverse function := $f^{-1} : B \to A$ with $f^{-1}(b)$ = the $a \in A$ with $f(a) = b$.
<!--SR:!2026-03-23,393,318-->