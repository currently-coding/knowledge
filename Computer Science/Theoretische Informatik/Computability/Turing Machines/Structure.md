![[Pasted image 20241101140959.png]]
## Control Unit
- always in a state from the finite set of states $S$
- a program $f$ controls the activity
- start state = $s_0$
- stop state = $s_1$

## Tapes
- divided into cells
	- each contains a symbol from $\sum$
- *infinite* on *both* sides
- empty symbol \[] $\in \sum$, separator symbol $* \in \sum$

## Heads
- 1 per tape
- can change field content
- can move to neighbouring field

# Working mechanism
## General
- in cycles
- start in special initial situation
- stop if state  $s_1$ is reached

- for each cycle the TM can do:
	- keep or change the state
	- change the $k$ symbols under the heads
	- move each head by one cell
- these actions depend on:
	- the state
	- the $k$ symbols the head is located on