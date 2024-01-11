#include <stdio.h>

int is_palindrome(int n) {
    int reversed = 0, temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }
    return n == reversed;
}

int main() {
    int max_palindrome = 0;
    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            if (product <= max_palindrome) break;
            if (is_palindrome(product)) max_palindrome = product;
        }
    }

    FILE *file = fopen("102-result", "w");
    if (file != NULL) {
        fprintf(file, "%d", max_palindrome);
        fclose(file);
    }

    return 0;
}
