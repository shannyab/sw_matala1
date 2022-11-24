#include <stdio.h>
#include "NumClass.h"

int main() {
    int first_num, second_num, i;

    scanf("%d%d", &first_num, &second_num);

    printf("The Armstrong numbers are:");
    for (i = first_num; i <= second_num; ++i)  {
        if (isArmstrong(i)) printf(" %d", i);
    }

    printf("\nThe Palindromes are:");
    for (i = first_num; i <= second_num; ++i) {
        if (isPalindrome(i)) printf(" %d", i);
    }

    printf("\nThe Prime numbers are:");
    for (i = first_num; i <= second_num; ++i) {
        if (isPrime(i)) printf(" %d", i);
    }

    printf("\nThe Strong numbers are:");
    for (i = first_num; i <= second_num; ++i) {
        if (isStrong(i)) printf(" %d", i);
    }

    printf("\n");

    return 0;
}
