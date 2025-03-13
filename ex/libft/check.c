#include "libft.h"
int main()
{
	char *str  = "Arina";
	printf(":%p\n", str);
	printf("::%c\n", str[0]);
	char a = str[0];
	printf("havata%c\n", a);
	printf("%p\n", &a);
}
