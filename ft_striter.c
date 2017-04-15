#include <stdlib.h>

void ft_striter(char *s, (*f)(char *s))
{
	while (*s)
	{
		f(&s);
		*s++;

	}
}
