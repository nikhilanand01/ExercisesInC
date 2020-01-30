#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("y is %d\n", y);
    printf("Hello, World!\n");
    return 0;
}

/*
1. subq	$16, %rsp; movl	$5, (%rbp)

2. The amount of instructions and lines significantly decreases as some instructions are gone.

3. movl	$5, %es is added

4. Without optimization x and y get assigned values and y is printed.
   With optimization x and y aren’t assigned but the value still gets printed?
   (Not really sure about this one)
 */
