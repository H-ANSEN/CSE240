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

> Where `+` indicates a positive inpact, and `-` indicates a negative impact

