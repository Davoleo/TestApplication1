TestApplication1

## Concepts
Source code is passed through a compiler 
that turns it into executable binaries.

C++ doesn't have a strict package/file structure like Java, it's just a way to feed the compiler source code

.obj files compiled by the compiler contain binary code

### Compiler:
1) Reads Preprocess statements
2) Tokenizing, parsing and translating cpp into a special abstract format
3) Converting the code into constant data &| Instructions
4) Generates machine code that the CPU executes

### Linker:
1) Find where each file and symbol is and link them together