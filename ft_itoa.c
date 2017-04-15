#include <stdlib.h>

int get_length(int n)
{
	int i;
	
	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

int get_power(int n)
{
	int i;
	int nb;

	i = -1;
	nb = 1;
	while (++i < n)
		nb *= 10;
	return (nb);
}

char *ft_itoa(int n)
{
	char *ctn;
	int len;
	int sign;
	int i;
	
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		len = get_length(n) + 1;
		n = -n;
	}
	else
		len = get_length(n);
	if(!(ctn = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ctn[len] = '\0';
	i = 0;
	if (sign < 0)
	{
		ctn[i] = '-';
		i++;
	}
	while (i < len--)
	{
		ctn[len] = (n % 10) + '0';
		printf("char:%c\n", ctn[len]);
		n = n / 10;
	}
	return (ctn);
}


int main()
{
	printf("itoa:%s\n", ft_itoa(-142));
	return (0);
}
