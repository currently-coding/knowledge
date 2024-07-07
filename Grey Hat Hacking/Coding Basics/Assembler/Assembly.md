---
tags:
  - hacking
  - coding
---
### Related to


# AT&T vs NASM
## AT&T
- used by GNU Assembler -> in `gcc` compiler suite
-> used by Linux Devs

## NASM
- Intel Syntax Assembler
- used by many Windows assemblers and debuggers

## Differences in Style and Format
```assembly
NASM -> CMD <dest>, <source> <; comment>
AT&T -> CMD <source>, <dest> <# comment>
```
### AT&T
`%` before Registers -> meaning *indirect operand*\
`$` before literal values -> meaning *immediate operand*\
handles memory differently



# Terminology
- Assembler = Application that translates code into *Assembly*
- *Assembly* = Assembly Language



# Flashcards
Where is NASM being used the most and where do people use AT&T ? -> Windows assemblers/debuggers; Linux Devs/gcc compilers

