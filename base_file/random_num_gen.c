#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize the random number generator with the current time
    int numbers[100];
    int i = 0;

    while (i < 100) {
        int number = rand() % 106 - 5; // generate a random number between -5 and 100
        int j;
        for (j = 0; j < i; j++) {
            if (numbers[j] == number) {
                break; // if the number is already in the array, break out of the loop
            }
        }
        if (j == i) { // if the number was not found in the array
            numbers[i] = number; // add it to the array
            i++;
        }
    }

    for (i = 0; i < 100; i++) {
        printf("%d ", numbers[i]); // print out the numbers separated by spaces
    }
    printf("\n"); // print a newline character at the end

	printf("median = %i", (-5 + 100) / 2);
    return 0;
}
