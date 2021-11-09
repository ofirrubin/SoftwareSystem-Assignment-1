# include <math.h>
# include "numclass.h"

int lengthRec(int n){
    if (n < 10) return 1;
    return 1 + lengthRec(n/10); 
}

int isArmstrongHinted(int n, int orgPow){ // Checks if a number is armstrong in recursion, the power is hinted.
    if (n < 10) return pow(n,orgPow);
    return pow(n % 10, orgPow) + isArmstrongHinted(n / 10, orgPow);
}

int isArmstrong(int n){ // Returns 1 if a number is armstrong number, 0 otherwise.
// Armstrong number is a number which the sum of each digit^<num_len> equals the num itself.
    int powr = lengthRec(n);
    return (isArmstrongHinted(n, powr) == n);
}

int isPalindromeHinted(int n, int placement){
    int digit = (int)(n / placement);
    if (n <= 0) return 1;
    return (digit % 10 == (int)(n%10)) && isPalindromeHinted( (n - digit * placement) / 10, placement / 100);

}

int isPalindrome(int n){ // Returns 1 if n is palindrome, 0 otherwise.
    if (n < 10) return 1; // A single digit number is palindrome.
    int place = pow((double)10, (double)lengthRec(n) - 1); // What digit are we currently working on?
    return isPalindromeHinted(n, place);
}
