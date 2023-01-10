# Syntax Graphs
Similiar to **[Backus-Naur Form (BNF)](https://github.com/H-ANSEN/CSE240/blob/master/M1/StructuresAndErrorTypes.md)** a language can also be defined by a **syntax graph**:

```Java
start --------> if (conditional) statement; -----------------------------------> end
                                                 |                     ^
                                                 |__ else statement; __|
                                                    
```
The syntax graph above defines a simple conditional *if-else* statement, where flow through the graph begins on the left side at `start` and follows the path outlined by the arrows. First a conditional is checked against, if it is true the statement immediatly following executes and `end` is reached. If the conditional is false the branch is taken and the else statment is executed. Syntax graphs can offer a more readable way to define the structure of a language at the cost of some ambiguity. Lets look at another, this time we will create a syntax graph for a switch statement:

```Java
start --------> switch (expression) { ---> case value: statement; ----------------------------------> } ---> end
                                       ^                          | |                          ^
                                       |__________________________| |__  default: statement; __|
                                                    1                             2   
```
> From `start` a switch statement must have the key word *"switch"* followed by an expression to match against in parentheses. Next case values are defined to match against the expression, the first branch labled **1** allows us to define as many case statements as we want following a loop. The branch labled **2** defines an optional branch in which a catch all *default* case is defined.

Most often BNF prefered when defining the structre of a language be cause of it's brevity. In some cases  syntax graphs are an elegent solution, one such example is defining the structure of **[JSON](https://en.wikipedia.org/wiki/JSON) (`J`ava`S`cript `O`bject `N`otation)**, a general storage format used in web platforms.

```html
                                          |--------> <number> -------->|
                                          |--------> <string> -------->|
                                          |--------> <object> -------->|
                           value ---------|--------> <array>  ---------|------->
                                          |-------->  true    -------->|
                                          |-------->  false   -------->|
                                          |-------->  null    -------->|
```

One of the most basic things we might want to store in a JSON file is a value, the syntax graph above defines structure in which we can store our value. Each of the banches surrouned by brackets can be defined further by its own syntax graph, below is syntax graph for storing a number in JSON:

```html
                                    |-------------|
start --------------------> 0 ----------> . ------------------------------------------------------------> end
       |        ^   |               ^           |      |                                       ^
       |        |   |               |           |      |-> e ->|___|-> + ->|------> <digit> ---|
       --> '-' --   --> <digit1-9> --------------      |-> E ->|   |-> - ->|  ^              |
                                    ^           |                             |______________|
                                    |_ <digit> _|
```
- a number can either be positive or negitive this is represented by the first loop
- a number can have either one leading zero or no leading zeros
- an optional point can be included `(1.2)` optionally followed by any number of digits
- the last branch allows for scientific notation to be defined

We begin to see the down side of syntax graphs here while readable the graph is complex and might not be immeditily clear as to what its function is. In addition, if we where to create a syntax graph for a language like Java the complexity would be exponiental.