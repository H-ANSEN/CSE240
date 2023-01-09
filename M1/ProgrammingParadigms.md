# Programming Paradigms

## Aspects of Programming Languages
At a conceptual level we use programming languages to solve problems. We solve these problems using diffrent styles and stratigies based on the programming language we are using, certian languages promote diffrent styles and stratiges of problems solving. Generally programming languages are grouped by these styles and stratiges. Often this grouping's of languages are called **Programming Paradigm**'s.

> What criteria do we use to evaluate programming languages?
- `Reliability` given a correct program it should always produce expected results and behavior 
- `Readability` how easy it is to read and understand what a program is doing
- `Writability` the quality of a language that allows a programmer to express computation clearly and correctly
- `Reusability` the abaility to reuse chunks of already written code in new unrelated programs
- `Efficiency`  support for fast operations with less memory

Depending on the application of a programming language the importance of each of these variables may vary. A relationship between a languages features and the evaluation metircs above can be created:

> Where `+` indicates a positive inpact, and `-` indicates a negative impact

| **Language Features/Performance Metrics** | **Efficiency** | **Readability/Reusability** | **Writability** | **Reliability** |
| ----------------------------------------- |:--------------:|:---------------------------:|:---------------:|:---------------:|
| **Simplicity/Orthogonality**              | `+`            | `+`                         | `+`             | `+`             |
| **Good Control Structures**               | `+`            | `+`                         | `+`             | `+`             |
| **Good Data Types & Structures**          | `+`            | `+`                         | `+`             | `+`             |
| **Good Syntax Design**                    |                | `+`                         | `+`             | `+`             |
| **Support For Abstraction**               |                | `+`                         | `+`             | `+`             |
| **Expressiveness**                        |                |                             | `+`             | `+`             |
| **Strong Type Checking**                  |                |                             | `-`             | `+`             |
| **Exception Handling**                    |                |                             |                 | `+`             |
| **Restricted (limit) aliasing/pointer**   | `-`            | `+`                         | `-`             | `+`             |

## Development of Programming Languages
The **Stored Program Concept *(von Neumann machine)*** was developed in the late 1940s. In this concept a computer stores program instructions in memory as opposed to systems that stored program instructions with plugboards or similar mechanisms. At the lowset level of these systems a program is represented as a sequence of bits *(binary numbers)* called **macine code** where bits represent instructions.

Machine language or machine code was very difficult for humans to work with, all instructions and their corrisponding numbers had to be remembered. This difficulty led to an abstraction one level higher than that of machine code; **assembly language**. In assembly language use of mnemonics *(certain symbols)* in place of bits allowed programs to become more readable and reuseable. In addition assembly language provided simple variables, conditionals, and macros allowing programs to become more sophisticated.

> Assembly language requires a program written in machine code called a **assembler** that translates assembly language to machine code

As tasks became larger and machines became more powerful higher-level programming lanuguages were created, languages like Autocode, FORTRAN, COBOL, LISP, Scheme, C, ...

These early languages where primarly influenced by hardware limitations of the time. Hardware was slow and memory was scarce, the main emphasis behind language devlopment was `efficiency` of the runtime.

As time went on and the devlopment of **compiler** technology evolved allowing higher levels of abstraction, languages also needed to evolve to support this abstraction and the ability to create larger programs. As languages evolved the need to write bigger programs was satisfied by designing languages that catered to the following:

- **Code Reuseability** - programs grew larger and the ability to reuse code became more important when consittering devlopment time
- **Readability** - large programs needed to be concise and easy to read so the code could be reused or extended

**Emergence of structred programming: Algol, Pascal, C**

The main idea of structural programming was to have a higher level of of abstraction from the machine code, structred programming allowed for single instructions to be compiled into multiple machine level instructions. This higher level abstraction allowed for eaiser more writable programming. The focus was on the structure of the program where a program could be thought of small logical units that accomplished subtasks that could be combined to preform a bigger task.

One of the main features of structural languages was the use of procedures that allowed a programmer to give names to subtasks and use the name to elsewhere in a program to preform the subtask. With the use of procedures also came scope, the idea that certan values are only defined within a certain subtask, once the subtask finished the value was no longer stored.

**Object-Oriented Programming**

Even higher levels of abstraction than structural languages was object oriented languages where heigherarcy of objects could be defined. These languages promoted a 

## Programming Paradigms
A paradigm is a coherent set of methods that are effective in handling a given type of problem. In programming languages the basic principles of how a computation or an algorithim is expressed can be grouped into a paradigm. There are two main approaches

- **Imperative (Non-Declarative)** - *focuses on how to execute*
    - defines control flow as statements that change a programs statements
    - makes the algorithm explicit and leaves the goal implicit
```Java
int imperativeFunction(int n) {
    int t = 1;
    while (n > 0) {
        t = t * n;
        n = n - 1;
    }
    return t;
}
```
> Looking at the imperative function above it is not explicit in what the function is trying to achieve *(computes factorial of n)*

- **Declarative** - *focuses on what to execute*
    - defines only program logic; control flow is generated during execution
    - makes the goal explicit and leave the algorithm implicit
```Rust
fun declarativeFunction(0) = 1
|   declarativeFunction(n) = n * declarativeFunction(n - 1)
```
The two main approaches above can be broken down even further:

- **Non-Declarative**

    - **Imperative/Procedural** - *the fully specified and fully controlled manipulation of named data in a step-wise fashion*
        - Based on the *Von Neumann* architecture of a computer
        - A program is a sequence of statements and procedure definitions
        - Primarily supports top-down problem-solving approaches
        - *E.g*, Assembly, Fortran, COBOL, BASIC, Ada, Pascal, C 

    - **Object-Oriented** - *encapsulation of state of the program in objects, which can be accessed only through operations defined on them. Other features include inheritance and polymorphism*
        - Based on the concept of objects that contain both data and code
        - A program is a sequence of class/object definitions
        - Primarily supports bottom-up problem-solving approach
        - *E.g.*, Smalltalk, Java, C++, Python, C#

- **Declarative**

    - **Functional** - *focus on higher level of abstraction (free from programming detail), simpler semantics, closer to mathematical functions and referential transparency (no side-effects)*
        - Based on the mathematical notation of Lambda Calculus
        - A program is a collection of function definitions
        - Treats computation as evaluation of mathimatical funations
        - *E.g.*, Scheme/LISP, ML, Haskell, F#, Scala

    - **Logical** - *a program is a set of facts about objects, rules about objects, and defining and questioning relations between object. The gola is to get rid of programming altogether*
        - Based on the mathimatical notation of First Order Logical
        - A program is a collection of predicate definitions
        - Primarily support rule-based approach to problem-solving
        - *E.g.*, Prolog *(Sicstus, SWI, GNU, YAP, Ciao)*

