#include <iostream>
int main () {
    // 25u => unsigned 25 integer (default on 32 bit) => max value is 2^32 = 4,294,967,296
    // The next value after 2^32-1 is 0 => integer acts likes a modulo operator ([2^32])
    // 25 - 50 = -25 % 2^32 =  4294967271
    std :: cout << 25u - 50;
}