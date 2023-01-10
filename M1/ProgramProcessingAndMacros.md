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