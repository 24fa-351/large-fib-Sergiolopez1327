#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_iterative(unsigned long long fibIndex) {
    if (fibIndex <= 2) {
        return fibIndex - 1;
    }

    unsigned long long previous = 0;
    unsigned long long current = 1;

    for (unsigned long long iter = 3; iter <= fibIndex; iter++) {
        unsigned long long next;
        next = previous + current;
        previous = current;
        current = next;
    }

    return current;
}

unsigned long long fib_recursive(unsigned long long fibIndex) {
    if (fibIndex <= 2) {
        return fibIndex - 1;
    }

    return fib_recursive(fibIndex - 1) + fib_recursive(fibIndex - 2);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <integer> <method>\n", argv[0]);
        return 1;
    }

    unsigned long long input_number = atoi(argv[1]);
    char fib_method = argv[2][0];

    unsigned long long result;
    if (fib_method == 'i') {
        result = fib_iterative(input_number);
    } else if (fib_method == 'r') {
        result = fib_recursive(input_number);
    } else {
        fprintf(
            stderr,
            "Invalid method. Use 'i' for iterative or 'r' for recursive.\n");
        return 1;
    }

    printf("%llu\n", result);

    return 0;
}