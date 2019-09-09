#include <cstdio>
#include <limits>

int main()
{
    /* After some trial and error and reading the printf(...) documentation 
     * available on cplusplus.com I realized that the width of the variadic
     * arguments supplied to printf(...) underwent promotions unless the 
     * width of the type was specified. There is a table which specifies the
     * format specifiers for these types here: 
     * http://www.cplusplus.com/reference/cstdio/printf/
     * I settled on the format specifier "02hhX" to print two characters 
     * precceded by 0 if the length of the value is less than two characters
     * long, and hh to specifiy that the width of the print type as unsined 
     * char, and X to print in uppercase hex. I have precceded each printed
     * value with the identifier 0x.
     */
    char const MAX_CHAR{ std::numeric_limits<char>::max() };
    char const MIN_CHAR{ std::numeric_limits<char>::min() };
    std::printf("0x%02hhX <= char <= 0x%02hhX \n", MIN_CHAR, MAX_CHAR); 
    
    unsigned char const MAX_UNSIGNED_CHAR{ std::numeric_limits<unsigned char>::max() };
    unsigned char const MIN_UNSIGNED_CHAR{ std::numeric_limits<unsigned char>::min() };
    std::printf("0x%02hhX <= char <= 0x%02hhX \n", MIN_UNSIGNED_CHAR, MAX_UNSIGNED_CHAR); 
}
