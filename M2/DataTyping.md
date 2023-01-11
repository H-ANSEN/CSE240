
# Data Typing

## Types

Programs are based around manipulating and preforming operations on data. If we want our programs to work in this way we need to make sure the languages we are using have robust features and support for data manipulation. Typically languages store data in data types and use various features such as type checking to ensure saftey of our programs.

- **A data type**
    - is defined by the set of primary *values* allowed and *operations* on thoes values
    - is used tp declare variables *e.g., integer, real, array of integer, string, ect.*
- **Type checking *(contextual)***
    - a feature of programming languages that ensures that types of operands of an operator are *legal* or *equivalent* to the legal type
- **Type equivalence**
    - rules that define how two types can be compared
    - to support type checking we need to be able to define type equivalence, this is the main idea behind type checking

Type equivalence can be defined by two main senses of equivalence:

- **Structural Equivalence**: In structural equivalence two types are equivalent if they have the same set of data and the same operations are expressed over that data *(structurally equivalent because they act the same)*.
    
    - *Used by Algol 68, Pascal, and non-structured C types*

- **Name Equivalence**: In name equivalence two types are equivalent if they have the same name. Even if two types hold the same data and support the same operations over that data but they have diffrent names they are not equivalent. Below is an example in Java of two classes that are **not** equivalent.

    - *Used by Ada and C-structure*

```Java
// Not equivalent under Name Equivalence
// Equivalent under Structural Equivalence

class Point2D {
    int x;
    int y;
}

class Vector2D {
    int x;
    int y;
}
```

**Strong vs Weak Type Checking**

In programming language design languages implement type checking in two different forms; **strong** type checking and **weak** type checking. Type checking is not binary though, languages implement type checking on a spectrum between weak and strong type checking.

- **Strong Type Checking**: a language that is strongly typed is one in which;
    - each name in a program has a single type associated with it
    - the type is known at compile time
    - type errors are always reported
    - tradeds flecibility for readability

- **Weak Type Checking**: a language that is weakly type is one in which;
    - a name can possibly have any number of types associated with it at some point during execution
    - type is not known at compiler time
    - looser typing rules that may produce unpredictable results

No language is fully strong or weak, they all make compromises

- Pascal/Modula-2 is neraly strongly typed
    - allows omission of type checking in its variant record *(union type in C)*
    - It allows `n = i + j;` where i in integer and j is real
- Ada and Java are nearly strongly typed
    - The allow type checking suspension for a particular type conversion by calling a library function UNCHECKED_CONVERSION
- C++ is less strongly typed and C is even less strong
    - not only: union yupe is noy type checked
    - but also many types are not checked, `char=int`

**Type Coversions**

Sometimes we want to convert between two data types, there are two main types of conversion that that can be preformed: ***coercion*** *(implicit conversion)* and ***casting*** *(explicit conversion)*. 

- coercion conversion between two types is implicit, conversion is preformed by the compiler/interpreter
- casting conversion between two types is explicit, type conversion is explicitly defined within a program 

```Java
int x = 5;

// Coercion: Implicit type converison
float f = 3.14 + x;

// Casting: Explicit type converison
int i = (int) f + x
```
