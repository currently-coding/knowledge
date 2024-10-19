>[!Idea]
> Assume and show $A \land \lnot B$ and infer a contradiction -> Assumption was wrong -> Impossible for $A$ to be true if $B$ is not -> $A \Rightarrow B$
>

## Example

>Let us prove that every natural number greater than 1
>has a divisor that is prime (prime divisor)

### Proof
- Assume there exists some number $p$ that is the smallest number without a prime divisor.
- Since $p$ is no prime it is a compound of $2$ numbers: $p = r \cdot s$
- As $r < p$, $r$ has a prime divisor: $r = t \cdot u$
- Then $p = t  \cdot u \cdot s$ => $p$ has a prime divisor => Assumption was wrong
=> Every natural number > 1 has a prime divisor