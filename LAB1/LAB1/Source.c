#include <string.h>

void foo(char *bar)
{
	char  c[12];

	strcpy(c, bar);  // no bounds checking
}

int main()
{
	foo("EiEIEiEiEIEIEi");
	return 0;
}