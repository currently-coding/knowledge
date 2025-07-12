- specifies how the DFA processes input. 
## Example $\delta$
- $w = a_1a_2\cdot \cdot \cdot a_2$ is the input and the machine is in the start state $s_0$.
1. $\delta(s_0, a_1)$ returns the state *after* the 1st character, e.g. $q_1$
2. $\delta(q_1, a_2)$ returns the state *after* the 2nd character, e.g. $q_2$
3. ...
m. $\delta(q_{m-1}, a_m)$ returns the state after reading the *entirety* of $w$, e.g. $q_m$

## Extending the function
=> we can only read from the last state $q_m$ whether the automaton accepts the input. (- only if $q_m \in F$.)
- this is not efficient. Thus we extend the behavior of the transition function

### Inductive Definition
