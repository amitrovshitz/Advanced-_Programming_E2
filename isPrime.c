#include <stdio.h>
#include <stdbool.h>
#include <time.h> 

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE *outputFile;
    outputFile = fopen("prime_numbers.txt", "w"); // Open the file for writing
    int count = 0;
    if (outputFile == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    // Starting from 2 to 2100000000
    for (int i = 2; i*i <= 2100000000; i++) {
        if (isPrime(i)) {
            fprintf(outputFile, "%d\n", i); // Write the prime number to the file
            count++;
        }
    }

    fclose(outputFile); // Close the file

    printf("%d Prime numbers up to 2100000000 have been written to prime_numbers.txt.\n",count);

    return 0;
}
