# include <stdio.h>
# include "numclass.h"


int main(){
    int low, high, temp;
    scanf("%d", &low);
    scanf("%d", &temp);
    if (temp < low){
        high = low;
        low = temp;
    }
    else{
        high = temp;
    }
    if (low < 0){ // If low < 0 than high < 0
        printf("You entered a negative number. Which is invalid value, the program will now exit.");
        return 1;
    }    // Not efficient but I prefer time over memory.
    printf("The Armstrong numbers are:");
    for (int i=low; i <= high; i ++){
        if (isArmstrong(i))
            printf(" %d", i);
    }
    printf("\nThe Palindromes are:");
    for (int i=low; i <= high; i ++){
        if (isPalindrome(i))
            printf(" %d", i);
    }
    printf("\nThe Prime numbers are:");
    for (int i=low; i <= high; i ++){
        if (isPrime(i))
            printf(" %d", i);
    }
    printf("\nThe Strong numbers are::");
    for (int i=low; i <= high; i ++){
        if (isStrong(i))
            printf(" %d", i);
    }
    return 0;
}