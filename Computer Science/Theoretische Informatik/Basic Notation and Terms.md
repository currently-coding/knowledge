## Basic
- Bracketing mathematical expressions: $\lparen \rparen$, $\brack$
- Function Arguments: $\lparen \rparen$
- Bracketing [[#Set|Sets]]: $\brace$

>[!Note]
>0 is a **natural** number $0 \in \mathbb{N}$
>

## Set
### Definition
$\mathbb{N}$ := $\{0, 1, \ldots\}$ (Set of natural numbers)
<!--SR:!2024-12-26,64,314-->
$\mathbb{N}^+$ := $\{1, 2, \ldots\}$ (Set of positive natural numbers)
<!--SR:!2024-12-18,56,314-->
$\mathbb{P}$ := $\{2, 3, 5, 7, 11, 13, 17, \ldots\}$ (Set of primes)
<!--SR:!2024-11-18,33,294-->
$\mathbb{Z}$ := $\{\ldots, -2, -1, 0, 1, 2, \ldots\}$ (Set of integers)
<!--SR:!2024-12-22,60,317-->
$\emptyset$ := empty set
<!--SR:!2024-11-21,36,290-->
Important: $0$ is a natural number.
For $x \in N$, $y \in N^+$ let $(x \mod y)$ := $x - zy$, where $z \in N$ is the greatest number with $zy \leq x$. (just a reminder)
<!--SR:!2024-12-21,59,314-->
### Element relationship and inclusion
$a \in M$ ::: $a$ is an element of the set $M$
<!--SR:!2024-12-27,60,314!2024-12-21,59,318-->
$a \notin M$ ::: $a$ is no element of the set $M$
<!--SR:!2024-12-24,57,318!2024-12-31,69,317-->
$M \subseteq N$ ::: for all $a$, if $a \in M$, then $a \in N$
<!--SR:!2024-12-22,60,314!2024-12-13,46,298-->
$M \not\subseteq N$ ::: it does not hold $M \subseteq N$
<!--SR:!2024-12-05,43,298!2024-12-31,64,314-->
$M \subsetneq N$ ::: $M \subseteq N$ and $M \neq N$ (M is proper subset of N)
<!--SR:!2024-11-17,32,294!2024-12-07,45,298-->
### Operations
$A \cap B$ := $\{a \mid a \in A \text{ and } a \in B\}$ (Intersection of A and B)
<!--SR:!2024-11-14,8,174-->
$A \cup B$ := $\{a \mid a \in A \text{ or } a \in B\}$ (Union of A and B)
<!--SR:!2024-12-12,50,297-->
$A \setminus B$ := $\{a \mid a \in A \text{ and } a \notin B\}$ (Difference of A and B)
<!--SR:!2024-12-09,42,277-->
$A - B$ := $A \setminus B$ (Difference of A and B)
<!--SR:!2024-11-07,24,274-->
$A^c$ := $M \setminus A$ (Complement of A relative to a fixed base set M)
<!--SR:!2024-12-25,54,274-->
$P(A)$ := $\{B \mid B \subseteq A\}$ (Power set of A)
<!--SR:!2024-11-27,35,274-->
$\#A$ or $|A|$ ::: number of elements of a finite set A
<!--SR:!2024-12-17,55,310!2024-12-13,46,299-->
## Tuple
$(a_1, a_2, \ldots, a_n)$ := sequence of elements $a_1, a_2, \ldots, a_n$ in this order (n-tuple, n-dimensional vector)
<!--SR:!2024-12-29,67,314-->
### Cartesian Products
$A_1 \times A_2 \times \ldots \times A_n$ := $\{(a_1, a_2, \ldots, a_n) \mid a_i \in A_i \text{ for all } i\}$ (Cartesian product of sets $A_1,A_2, \ldots, A_n$)
<!--SR:!2025-03-14,119,297-->
$A^n$ := $A \times A \times \ldots \times A$ (n-dimensional Cartesian product of set A)
<!--SR:!2024-12-07,45,294-->
The first definition yields the empty tuple $( )$ for $n = 0$. Thus $A^0 = \{( )\}$ and $|A^0| = 1$.
## Quantifiers
$\exists$ := “there exist(s)”
<!--SR:!2025-01-03,67,314-->
$\forall$ := “for all”
<!--SR:!2024-12-15,53,317-->
## Functions
### Definition 1.1
$f : A \to B$ is determined by the source set (aka domain) $A$, the target set (aka codomain) $B$, and the graph $G_f \subseteq A \times B$, where for every $a \in A$ there is at most one $b \in B$ with $(a, b) \in G_f$
If $(a, b) \in G_f$, then $f(a)$ = $b$.
If there is no $b \in B$ with $f(a) = b$, then $f(a)$ is not defined (notation: $f(a) = n.d.$).

$g \circ f$ := $f : A \to C$ with $(g \circ f)(x)$ := $g(f(x))$ (composition of functions).
<!--SR:!2024-11-09,24,274-->
$D_f$ := $\{a \in A \mid \exists b \in B \text{ with } f(a) = b\}$ (Domain of definition of f)
<!--SR:!2024-11-07,24,274-->
$R_f$ := $\{b \in B \mid \exists a \in A \text{ with } f(a) = b\}$ (Range of f)
<!--SR:!2024-12-01,39,290-->
$f$ is total ::: $D_f = A$
<!--SR:!2024-11-22,37,294!2025-02-13,90,319-->
$f$ is surjective ::: $R_f = B$
<!--SR:!2025-02-19,96,298!2024-11-21,29,274-->
$f$ is injective ::: $f(a_1) \neq f(a_2)$ for all distinct $a_1, a_2 \in D_f$
<!--SR:!2024-12-12,36,258!2025-03-01,106,294-->
$f$ is bijective ::: $f$ is total, surjective, and injective
<!--SR:!2025-01-04,68,314!2025-01-09,69,318-->
If $f$ is injective, there exists the inverse function := $f^{-1} : B \to A$ with $f^{-1}(b)$ = the $a \in A$ with $f(a) = b$.
<!--SR:!2024-11-09,24,278-->