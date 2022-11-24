#include <math.h>
#include "NumClass.h"

int isArmstrong(int n) {
    int digit_sum = 0, sum = 0, x = n;

    while(x > 0) {
        x=x/10;
        ++digit_sum;
    }

    x = n;

    while(x > 0) {
        sum= pow(x%10, digit_sum)+sum;
        x=x/ 10;
    }

    return (sum == n);
}

int isPalindrome(int n) {
    int sum=0, x=n;
    
    while (x > 0) {
        sum = x%10 + (sum*10);
        x /= 10;
    }

    return (sum ==n);
}
