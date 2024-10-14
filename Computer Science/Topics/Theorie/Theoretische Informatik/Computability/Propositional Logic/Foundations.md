>[!General]
>Mathematical statements are always either true(1) or false(0).

## Logical connections
| Natural Language             | Meaning     | Symbol            |
| ---------------------------- | ----------- | ----------------- |
| and                          | conjunction | $\land$           |
| or                           | disjunction | $\lor$            |
| not                          | negation    | $\lnot$           |
| if ..., then ....            | implication | $\Rightarrow$     |
| if and only if .... then ... | equivalence | $\Leftrightarrow$ |
- prefer natural language over symbols
>[!Note]
>Avoid using equivalence at first as it may lead to many errors.
>Instead prove both implications *separately*

## Truth Tables
| A   | B   | ¬A  | A ∧ B | A ∨ B | A ⇒ B | A ⇔ B |
| --- | --- | --- | ----- | ----- | ----- | ----- |
| 1   | 1   | 0   | 1     | 1     | 1     | 1     |
| 1   | 0   | 0   | 0     | 1     | 0     | 0     |
| 0   | 1   | 1   | 0     | 1     | 1     | 0     |
| 0   | 0   | 1   | 1     | 0     | 1     | 1     |
>[!Note]
>Everything is implied by a false statement.

>[!Note]
>Negation of "Each prime is odd" is "There exists an even prime"

