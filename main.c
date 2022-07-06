#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf(NULL);
	len2 = printf(NULL);
	printf("%d\n%d\n", len, len2);	
return (0);
}
