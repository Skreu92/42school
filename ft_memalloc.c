#include <stdlib.h>
#include <string.h>

void *ft_memalloc(size_t size)
{
	char *str;

	str = malloc(size);
	if(!str)
		return NULL;
	while (size--)
		str[size] = 0;
	str[size] = 0;
	return (str);
}
