#include <math.h>
#include "NumClass.h"

int fac(int);

int isPrime(int n) {
    if(n ==0)
        return 0;

    int i;

    for(i =2; i <sqrt(n); ++i){
        if (n%i == 0)
            return 1;
    }

    return 0;
}

int isStrong(int n) {  
    int x = n, sum = 0;

    while (x>0) {
        sum = fac(x%10)+sum;
        x = x/10;
    }

    if (sum==n){
        return 1;
    }
    else{
        return 0;
    }
}

int fac(int n) {
    if(n == 0){
       return 1;
    }  
     return n*fac(n-1);
}
