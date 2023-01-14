/*
    Formatted IO in C allows the programmer to specifiy the format in which symbols are
    converted to when using input/output functions. Format is typically specified in a
    control sequence defining a type of data to format to:

    - %d    for integer
    - %f    for floating pint, or %5.2f (at least 5 wide and a precision of 2)
    - %c    for character
    - %s    for string of characters

    To use IO functions in C we have to include:
*/
#include <stdio.h>

int main() {

    /*
        In C `printf()` is one of the main output functions, sending output to the 
        screen. Below we use contol sequences to output data in a format we specify:
    */
    int x = 1;
    float y = 3.14;
    printf("x = %d, y = %f\n", x, y);

    /*
        In the same way we can store data taken from the user using scanf:
    */
    printf("Enter a integer value: ");

    // scanf takes in an intger value and stores it at the address of variable x
    scanf("%d", &x);

    printf("You entered: %d", x);

    return 0;
}

