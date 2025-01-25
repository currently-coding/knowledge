1. Encoding of individual RAM instructions:
![[Pasted image 20241106161040.png]]
2. Encoding of RAM $M$ with instructions $b_1, ..., b_s$:
$\langle M \rangle$ = $\langle \langle b_1 \rangle, ..., \langle b_s \rangle \rangle$($b_{1}, ...$ are instructions) (Code einer RAM)
3. For $i \in \mathbb{N}$ let 
$$
 
\begin{cases}
	M \text{, if } i = \langle M \rangle \text{ for a RAM } M\\
	M^* \text{, if } i \text{ is not code of a RAM},
\end{cases}
$$
where $M^*$ is the RAM with the single instruction STOP.