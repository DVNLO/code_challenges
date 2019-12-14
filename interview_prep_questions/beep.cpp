#include <unistd.h>
#include <stdio.h>
int main()
{ 
	for(int i = 0; i < 5; ++i)
	{
		puts("\a ");
	}
	return 0;
}
