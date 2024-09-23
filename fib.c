#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_iterative(unsigned long long num) {
    if (num <= 2) {
        return num - 1;
    }

    unsigned long long previous_num = 0;
    unsigned long long current_num = 1;
    unsigned long long next_num;

    for (unsigned long long iter = 3; iter <= num; iter++) {
        next_num = previous_num + current_num;
        previous_num = current_num;
        current_num = next_num;
    }

    return current_num;
}

unsigned long long fib_recursive(unsigned long long num) {
    if (num <= 2) {
        return num - 1;
    }

    return fib_recursive(num - 1) + fib_recursive(num - 2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <integer> <method>\n", argv[0]);
        return 1;
    }

    unsigned long long input_number = strtoull(argv[1], NULL, 10);
    char fib_method = argv[2][0];

    unsigned long long result;
    if (fib_method == 'i') {
        result = fib_iterative(input_number);
    } else if (fib_method == 'r') {
        result = fib_recursive(input_number);
    } else {
        fprintf(stderr, "Invalid method. Use 'i' for iterative or 'r' for recursive.\n");
        return 1;
    }

    printf("%llu\n", result);

    return 0;
}