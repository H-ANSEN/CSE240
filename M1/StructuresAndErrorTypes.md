# Structures and Error Types

When we write a program we wirte it according to certian rules based on the language we are writing in. 

- Structure helps humans and computers agree on the behavior of code
- Structure helps to ensure that a compiler can process an input
- Structure also helps us to think of programs generically, thater than focus on a specific language

In general there are multiple diffrent levels of structure that you can find in a program:

- **Lexical** - *"tokens" the basic building blocks of a program*

    - **Identifiers**: Names *(programmer chosen)* of objects of intrest *(variables, procedures, ect.)* usally bound by length, case sensitivity, allowable characters ect.
    - **Keywords**: Names reserved by the language designer: *if, else, switch, int, float* 
    - **Operators**: +, -, <, ==
    - **Separators**: ;, (), . ect
    - **Literals**: numbers, characters, strings
    - **Comments**: // /* */
    - **Layout**: Some languages are of free format, while some are not, e.g., Python

    So what does the compiler see? Suppose we have the following snippet of Java code:
    ```Java
    int a, b, c;
    c = 2 * a + b;
    ```
    It will be analyzed by a part of the compiler called the **lexer** which finds the tokens in the input text. The result looks something like: [KEYWORD, IDENTIFIER, COMMA, IDENTIFIER, COMMA, ect...] typically there is metadata associated with each token

- **Syntatic**

    The **syntax** if a language describes how to put lexical units together to form valid sentences/statments. In the late 1950s, a concise and formal way of expressing syntax was introduced: **Backus-Naur Form (BNF)**. BNF acts like a meta-language for describing languages. Using mathematical terms, we say that it describes **context free languages (CFLs)**, and that it is a **Context-free grammer (CFG)**.

    A BNF description of a language contains two types of symbols:
    
    - **non-terminal symbol**: represents an "idea" to be decomposed - they do not appear in the final "sentence"

    - **terminal symbol**: appear in the actual sentence - no additional grammatical rules apply to them

    If we have a language, we could think about doing things like cheacking if a sentence is valid or generating a valid sentence. 

    > **Sample BNF for a Very Simple Language (VSL):**

    ```BNF
    <sentence>  ::= <subject> <verb> <object>
    <subject>   ::= <adjective> <noun>
    <adjective> ::= <adjective> | <adjective> <adjective>
    <object>    ::= <subject>
    <noun>      ::= table | horse | computer
    <adjective> ::= big | fast | good | high
    <verb>      ::= is | makes  
    ```
    In a way BNF describes replacement rules; a *\<sentence\>* becomes *"\<subject\> \<verb\> \<object\>"* and a *\<subject\>* becomes  *"\<adjective\> \<noun\>"* ect. Each symbol surrounded by brackets represets a **non-terminal** symbol. Symbols not surrounded by brackets are **terminal** symbols meaning there is no more replacement. Also note that the pipe `|` can be read as "or". Using this knowledge we can decent our grammer; VSL and create a *valid* sentence:

    ```BNF
                                                    <sentence>
                                                        |
                                            <subject> <verb> <object>
                                            /           |          \
                            <adjective> <noun>        makes      <subject>
                              /           |                             \
                            big         horse                          <adjective> <noun>
                                                                            |          \
                                                                         big fast    computer
    ```
    > The tree above defines a valid sentence "big horse makes big fast computer" in the grammer defined by VSL

- **Contextual**
- **Semantic**
