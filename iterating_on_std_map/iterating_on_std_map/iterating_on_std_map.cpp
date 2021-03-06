/*
I build the following example to explore the attributes of std::map iteration.
A small proof is provided below, the conclusion of which, is that the std::map
orders entries on the key.
*/

#include "pch.h"
#include <iostream>
#include <map>

int main()
{
	std::map<char, int> example;
	char c = 'z';
	unsigned const size = 26;
	for (unsigned i = size - 1; i != static_cast<unsigned>(-1); --i)
		example.insert({ c - i, i });
	for (auto const key : example)
		std::cout << key.first << ' ' << key.second << '\n';
}
/*
Despite inserting the items in reverse order, iteration through the map 
produces the ordering on proper order.
a 0
b 1
c 2
d 3
e 4
f 5
g 6
h 7
i 8
j 9
k 10
l 11
m 12
n 13
o 14
p 15
q 16
r 17
s 18
t 19
u 20
v 21
w 22
x 23
y 24
z 25

Now unfortunately, this output, above, doesn't answer the question of what is 
the ordering entity. Does the std::map order on the key or the value? For this,
we can flip the key ordering, so a -> 25, b -> 24, ... z -> 0. The output
following this modification is below.

a 25
b 24
c 23
d 22
e 21
f 20
g 19
h 18
i 17
j 16
k 15
l 14
m 13
n 12
o 11
p 10
q 9
r 8
s 7
t 6
u 5
v 4
w 3
x 2
y 1
z 0

Here, we can see that the std::map performs ordering on the key, despite a 
being the final key added to the std::map.

*/