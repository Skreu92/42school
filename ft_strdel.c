#include <stdlib.h>
#include <string.h>

void ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}
