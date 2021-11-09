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

int isPalindrome(int n){ // Returns 1 if n is palindrome, 0 otherwise.
// Palindrome number is a number which the i'th digit from the beginning equals the i'th digit from the end.
    if (n < 10) return 1; // A single digit number is palindrome.
    //if (n < 100) return (n%10) == 0; // 0D0
    int leng = lengthRec(n) - 1; // Gives the length of the number
    int place = pow((double)10, (double)leng); // What digit mult. are we comparing now to the lowest?
    int digit = (int) (n/place); // Here the digit will be stored.
    if (digit % 10 != (int)(n%10)) return 0; // If the digit from the beginning not equal to the digit from the end, return false.
    n = (n - place * digit) / 10; // We've seperated it as there is extreme case where we remove a digit (!= 0) that after that there are many zeros, thus X0..0abcd becomes abcd and the only case it's actually equal from both sides is if we were to remove zeros which means abcd must be zeros too, n is zero.
    if (n != 0 && leng - lengthRec(n) > 2) return 0; // If we removed the two digits and the new number length has a difference of more than 2 than we have to check it as described above.
    return isPalindrome(n);
}