#include "main.h"
#include <stdio.h>
int main(void)
{
	unsigned int n = 2147484671;
	int n2 = 526;
	printf("%u\n", n);
	_printf("%u\n", n);
	
	printf("%o\n", n2);
	_printf("%o\n", n2);

	printf("%x\n", n2);
	_printf("%x\n", n2);
	return 0;
}
