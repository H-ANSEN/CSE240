# Program Processing and Macros

## Program Processing Methodologies

In general there are three diffrent processing methodologies in which text in a program file is transformed into something that can run on your computer:

```
               Program Processing
              /        |         \
Interpretation    Compilation    Two Step Translation
    /                  |               /             \
 Scheme              C/C++        Compilation         Compliation
 Python             Prolog             +                   +
 JavaScript                      Interpretation       Compliation
                                 (Java Solution)    (C++/C# Solution)
```

- **Interpretation**

    In interpretation a program called an **interpreter** translates and executes each statement in the the high-level language, without first translating all statements into the executable code.

    *Advantages:*   
    - No separate commpilation phasa *(quicker development)*
    - Good debugging information since the source code is being executed
    
    *Disadvantages:*
    - Slow execution
    - Can use more memory space
    - Big/complex language may be difficult to interpret

- **Compilation**

    In compilation source code is translated all the way down to a binary format that a computers CPU and directly read and execute. The steos of the compilation process are listed below:

    1. ***Source Program*** - *your program file in human readable structure*
    2. ***Compiler*** - *translates the source program to a set of optimized assembly instructions*
    3. ***Assembler*** - *converts assembly instructions to machine code*
    4. ***Object Code*** - *output for of the assembler*
    5. ***Linker*** - *resolves external references (links code from different libraries and source files)*
    6. ***Runtime or Hardware*** - *steps though and executes the final file*

    *Advantages:*   
    - Faster than interpretation
    - Good for multi-module programs
    
    *Disadvantages:*
    - Separate compilation phase
    - May lose debugging info
    - Platform Compatibility

- **Two Step Translation/Intermediate**

    Intermediate is very general sense it is mostly implementation defined, the main idea behind the methodology is to combine the benifits of the previous two methodologies. In two step translation source code is translated into an intermediate represntation, this step comes with many advantages. In the case of Java your souce code is compiled to bytecode *(this is the intermediate representation)*, bytecode is then run on a vitural machine that generates instructions for whatever system it is implemented on. In this way implementations of the vitural machine can be made on any machine that you would be able to run your bytecode on.

    *Advantages:*
    - A single compiler for all machines
    - A small vitural machine that even fints in a web browser
    
    *Disadvantages:*
    - May lose debugging info
    - Can be difficult to optimize for the vitural machine when writing code

## Macros

**Macro-Processing** is a step that your compiler toolchain may apply to your program. The basic idea behind macros is to substitute a definition for a name in the program, similiar to a variable.

- Arguments are allowed, creating "in-line" functions. It eliminates invocation (function call) overheads
- Macro-processing occurs in the **preprocessing** phase of complilation

Lets look at an example of macros in the C programming language:

```C
#define AREA_OF_TRIANGLE(b, h) (b * h) / 2
int base = 3;
int height = 5;
float area = AREA_OF_TRIANGLE(base, height);
```

In the example a ***preprocssor directive*** is made, an instruction on how to transform this program during the preprocessing phase of compilation. Substitution is one of the most common preprocessor directives that is used and we are using it above, a definition is created using `#define` for a name `AREA_OF_TRIANGLE`, the preprocessor then looks through the source file for further references to this definition, if one is found the name is replace by the definition. The output of the preprocessor on the C code above would be:

```C
int base = 3;
int height = 5;
float area = (base * height) / 2;
```

Macros can be compared to fuction calls, although there can be peformance differences between the two, as an example take a look at the following C code that implements an absolute value function and computes the absolute value of 4 and prints it to the console:

```C
int abs(int a) {
    return ((a < 0) ? -(a) : (a));
}

int i = 3;
int j = abs(++i);
printf("j = %d", j);
```

Typically function calls are slower than macros, in some situations it is acceptable and faster to allow a macro to do the job of a function, here is the same program but using macros in place of a function:

```C
#define abs(a) ((a < 0) ? -(a) : (a))

int i = 3;
int j = abs(++i);
printf("j = %d", j);

// The preprocessor would convert the code above to the following macro expansion:
int i = 3;
int j = ((++i < 0) ? -(++i) : (++i));
printf("j = %d", j);
```

While the code above may run faster and take up less space we begin to see something called **side effects** which is the main difference between macros and functions and the reason why we program primarly using functions rather than macros. Our first example using a function would print `j = 4.0`, the second example using a macro would print `j = 5.0`. Each time `i` appears in the expansion of the macro it in incrimented creating undesired side effects.

> Note that macros and their behaviors are inconsistant across compilers
> - Using GNU GCC we can write `gcc -E fileName.c > outputFile.c` to get uncompiled source file with it's macros expanded 