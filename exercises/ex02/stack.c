/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}


/*
1: Print the address of arrays in foo() and bar(). The program should print "42" 5 times.

2: Warning: The function returns the address of stack memory associated with local variable array. This means foo() is trying to return a pointer to a local array that will be taken off the stack after the function ends.

3: A segmentation fault occurs. The address array in the main function is illegally
editing that same memory address creating this segmentation fault.

4: Warning: The local variable array in bar() is set but not used.

*/
