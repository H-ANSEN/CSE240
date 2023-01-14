# **C**: The Imperative Paradigm

There are three main attributes of the **C** programming language that makes it *imperative*:
- Programs in C are fully specified and fully controlled manipulation of named data in a stepwise fashion
- Languages developed as abstractions of *[von Neumann machines](https://github.com/H-ANSEN/CSE240/blob/master/M1/ProgrammingParadigms.md#user-content-development-of-programming-languages) (the stored program concept).*
- Programs that are algorithmic in nature: *do this, then that, then repeat this* -- focuses on **how** rather than **what**.

The basic building blocks of a C program are **functions**. There are two kinds of functions:
- Build-in finctions are pre-written and exist in **libraries**, *i.e.:* input and output functions, mathematical functions, ect..
- User defined functions are written by the programmer
- Functions may exist outside any class in C++, and variables may exist outside of any class or functions. These functions and variables are called **globals**.
- Each C/C++ program must contain exactly one `main()` function

## State

In the imperative paradigm data are represend by states - collections of variables and their values.

**Key concepts of data:**
- **type**: what values and operations are allowed
- **location**: where data are stored in *(physical)* memory
- **address**: an integer associated with *location*
- **reference/pointer**: a name associated with a variable that holds an address of a *location*
- **variable name**: a name associated with a *location*
- **value**: what is stored in a memeory location
- **scope**: *(lifetime)* and **visibility**

## Declaration
At the machine level, the value stroed in any memory locations is a sequence of bits *(bit pattern)*: `001011011..`

A variable declaration binds a **name** to a location in memory, and describes the **attributes** of the **value** in the location:

- **Type**: *(how should the bit pattern be interpreted)*
- **Scope**: *(existance and visibility)*
- **Qualifier**: *(modifiability, e.g., constant)*

Typically, the compiler allocates memory for the variable and binds the name to that loaction when a variable is declared.

Declaration in C:
```C
int i = 5;
int j = 6, k, l;
```
| **Name**   | **Address** | **Initial Value** |
|------------|-------------|-------------------|
| `i`        | 8000        | 5                 |
| `j`        | 8004        | 6                 |
| `k`        | 8008        |                   |
| `l`        | 8012        |                   |

## Scoping rules

In C and C++, variables and functions must be declared before use. The scope of a variable starts from its declaration point and extends to the end of the current block in a pair of braces. The following code is **only** valid because the variables `height` and `width` are declared before they are used to declare area.
```C
void main() {
    int height = 6; int width = 6;
    int area = height * width;
}
```
In C and C++ we can also create **forward declarations**, which make a name know before it is used. Since C and C++ uses onlt one pass *(top to bottom)* to compile a file, it needs to know about each function before it is called by another function.

- This is particularly important for something like a mutually recursive function: *function F calls G, and G calls F*
- Langauges like Java use a two-pass compiler so this step is not necessary in that language

Forward Declaration Example:
```C
void foo(void) {
    bar();
}

void bar(void) {
    k = foo();
}
```
> In the example above the compiler would start at the beginning of the file, it would read the contents of foo and throw an error saying that is does not know what the function `bar()` is sense the compiler has yet to see `bar`, this is fixed using a forward declaration:
```C
void foo(void);
void bar(void); 

void foo(void) {
    bar();
}

void bar(void) {
    k = foo();
}
```
> In this new example the compiler is now told explicitly that *"in this file is a function `void foo(void)` and `void bar(void)`"*