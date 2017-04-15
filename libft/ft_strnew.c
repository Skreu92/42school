#include <stdlib.h>
#include <string.h>

char *ft_strnew(size_t size)
{
	char	*str;
	
	str = malloc(size);
	if (!str)
		return (NULL);
	while (size--)
		str[size] = '\0';
	return (str);
}
