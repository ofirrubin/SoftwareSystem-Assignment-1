# include "NumClass.h"
# include <math.h>

int length(int n){
    int len = 0;
    while (n != 0){
        len ++;
        n /= 10;
    }
    return len;
}
// BY LOOP:
int isArmstrong(int n){ // Returns 1 if the number is armstrong number and 0 otherwise.
// armstrong number is a number whom sum of digit^len equals the number.
    int sum = 0;
    int power = length(n);
    int left = n;
    while (left != 0){
        sum += pow((double)(left%10), (double)(power));
        left /= 10;
    }
    return n == sum;
}

// RECURSION: We get a digit every time and power it to the required power, if it's equal to the current sum, substruct it from the sum and check the sum for n/10 with the same power.

// BY LOOP:
int isPalindrome(int n){ // Returns 1 if a number is palindrome and 0 otherwise.
// The function returns if every digit at i'th position from the beginning equals to the digit at the i'th from the end.
    // Best I see is O(2n) = O(n)
    if (n < 9) return 1; // A single digit number is palindrome.
    int leng = length(n) - 1; // Gives the length of the number
    int place = pow((double)10, (double)leng); // What digit mult. are we comparing now to the lowest?
    int digit = 1; // Here the digit will be stored.
    while(n > 0){
        digit = (int) (n/place);
        if (digit % 10 != (double)(n%10))
            return 0; // False

        n -= place * digit; // We eliminate the digit from the left.
        n /= 10; // Eliminate the digit from the right.
        place /= 100; // We are actually moving 2 steps at the time -> ... <- thus we eliminated 2 zeros.
    }
    return 1; // True
}
// Same principle at recursion, we eliminate the two digits at the corners and check for the inner corners.
