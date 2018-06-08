C program which could read the input source in assembler for abstract machine used in operational semantics and output will be lexical and syntax analysis, i.e. splitting the input string into instructions and checking their syntax
INPUT : assembler
OUTPUT : 


- page 64 (page 74 in pdf) - here you can see a syntax of ca. 14 instructions, this is complete language, nothing more

Example of input:
PUSH-1:FETCH-x:ADD:STORE-x => output is the list [PUSH-1, FETCH-x, ADD, STORE-x]

Another example:
FETCH-x:FETCH-y:LE:BRANCH(PUSH-1:FETCH-x:ADD:STORE-x, NOOP):PUSH-1:FETCH-x:ADD:STORE-x => here the output is [FETCH-x, FETCH-y, LE, BRANCH(PUSH-1:FETCH-x:ADD:STORE-x, NOOP), PUSH-1, FETCH-x, ADD, STORE-x ]
- so the instructions BRANCH() and LOOP()  are considered as atomic ones with their content inside the brackets, parsing of inner instructions is given in another recursive run of parser