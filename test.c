#include <stdio.h>
#include "main.h"

int main(void)
{
	int b = 15;
	int *a = &b;
	
	printf("%d\n", &b);
	printf("%p\n", a);
	_printf("%p\n", a);
	return 0;
}
