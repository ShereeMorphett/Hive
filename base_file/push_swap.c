#include <stdio.h>

 // test case

void sa() {
    // Swap the first 2 elements at the top of stack a.
    int temp = a[0];
    a[0] = a[1];
    a[1] = temp;
}

void ra() {
    // Shift up all elements of stack a by 1. The first element becomes the last one.
    int temp = a[0];
    for (int i = 0; i < 4; i++) {
        a[i] = a[i+1];
    }
    a[4] = temp;
}

void rra() {
    // Shift down all elements of stack a by 1. The last element becomes the first one.
    int temp = a[4];
    for (int i = 3; i >= 0; i--) {
        a[i+1] = a[i];
    }
    a[0] = temp;
}

void pa() {
    // Take the first element at the top of b and put it at the top of a.
    if (a[0] == 0) {
        a[0] = a[1];
        a[1] = a[2];
        a[2] = a[3];
        a[3] = a[4];
        a[4] = 0;
    }
}

void pb() {
    // Take the first element at the top of a and put it at the top of b.
    if (a[4] == 0) {
        a[4] = a[3];
        a[3] = a[2];
        a[2] = a[1];
        a[1] = a[0];
        a[0] = 0;
    }
}

void push_swap() {
    // Send top 2 numbers from a to b
    pb();
    pb();

    // Sort the remaining 3 numbers in a
    if (a[0] > a[1]) {
        sa();
    }
    if (a[1] > a[2]) {
        rra();
        if (a[0] > a[1]) {
            sa();
        }
        if (a[1] > a[2]) {
            sa();
            ra();
        }
    }
    else {
        ra();
        if (a[0] > a[1]) {
            sa();
        }
    }

    // Move the top 2 numbers from b to a
    pa();
    pa();

    // Sort the remaining 3 numbers in a
    if (a[0] > a[1]) {
        sa();
    }
    if (a[1] > a[2]) {
        rra();
        if (a[0] > a[1]) {
            sa();
        }
        if (a[1] > a[2]) {
            sa();
            ra();
        }
    }
    else {
        ra();
        if (a[0] > a[1]) {
            sa();
        }
    }
}

int main() {
	int a[5] = {1, 5, 2, 4, 3};
    push_swap();
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
