#include "big_uint.h"
// I implemented a class for handling these type of "Big integers" a year
// ago in the UWB GCSDD. I don't want to re-implement it so I'll just review
// the general approach here in text. 
// We can convert an input integer into a big integer by modulo and division 
// operations. For example the value 135 can be converted to a vector of 
// values { 5, 3, 1 } where the power of 5 is 10^0 3 is 10^1 and 1 is 10^2.
// This vectorized orientation of the integer types allows us to grow the data
// type and define operator operations for + , -, *, and / operations. We can 
// implement these operations just like we do by hand using a carry. We can 
// compute the sum in place by allocating a results array and iterating through
// the arrays of the operands X and Y to produce the result Z for the various
// operations. 
