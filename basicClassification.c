# include <math.h>
# include "NumClass.h"

int fact(int n){
    if (n <= 1) return 1;
    return n * fact(n-1);
}

int isPrime(int n){ // Returns 1 if a number is a prime number, 0 otherwise.
    // A prime number is a number which is divisible only by 1 and itself.
    // We can check up to the sqrt of the number as the (sqrt)^2 is the number it's self thus every multiplier should've been on the lower part of the graph.
    if (n < 1) return 0;
    if (n == 2 || n == 1) return 1; // 2 is the only even prime number, it appears that you count 1 as prime although it isn't.
    if (n % 2 == 0) return 0; // Every even number that is not 2 is not a prime number.
    int max = floor(sqrt((double)n));
    for (int i = 3; i <= max; i ++){
        if (n % i == 0) return 0;
    }
    return 1;
    }

int isStrong(int n){ // Returns 1 if a number is a strong number, 0 otherwise.
// A strong number is a number whose sum of fact(digit) == number
    if (n < 0) return 0; // Factorial can be done on natural numbers only.
    int tmp = n; // Used to extract digits
    int sum = 0; // Saves the sum of the factorials.

    while (tmp > 0){
        sum += fact(tmp%10); // Add the factorial of the current working digit
        tmp /= 10; // Eliminiate the digit added now.
    }
    return sum == n;
}
