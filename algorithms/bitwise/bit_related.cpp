#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map> //pairs
#include <unordered_set> //hash

using namespace std;

// Function to calculate xor
long computeXOR(const int n)
{
    // Modulus operator are expensive on most of the 
    // computers. n & 3 will be equivalent to n % 4.   
 
    switch(n & 3) // n % 4 
    {
    case 0: return n;     // if n is multiple of 4
    case 1: return 1;     // If n % 4 gives remainder 1  
    case 2: return n + 1; // If n % 4 gives remainder 2    
    case 3: return 0;     // If n % 4 gives remainder 3  
    }
}

      
 
/* Function to get no of set bits in binary
   representation of positive integer n */
 int countSetBits(int n)
{
    // Number of leading zeroes: builtin_clz(x)
    // Number of trailing zeroes : builtin_ctz(x)
    // Number of 1-bits: __builtin_popcount(x) 

    return __builtin_popcount(n);
}
 



// Driver code
int main()
{
    // your code goes here
    int n = 5;
    cout <<    computeXOR(n);
    return 0;
}
