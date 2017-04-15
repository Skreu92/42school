#include <stdlib.h>
#include <string.h>

int get_nb_words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

char *make_my_string(char const *s, char c, int nb)
{
	int i;
	char *ctn;
	int j;
	int k;

	j = -1;
	i = 0;
	while (++j <= nb)
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			k++;
		}
	}
	if (!(ctn = (char *)malloc((i + 1) * sizeof(char)))
		return (NULL);
	j = -1;
	while (++j < k)
		ctn[j] = s[i - k + j];
	ctn[j] = '\0';
	return (ctn);
}

char **ft_strsplit(char const *s, char c)
{
	char **tab;
	int i;
	int words;

	words = get_nb_words(s, c);
	i = 0;	
	tab = (char **)malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);	
	tab[words] = NULL;
	while (i < words)
	{
		tab[i] = make_my_string(s, c, i);
		i++;
	}
	return (tab);
}

int main()
{
	char d[30] = "**coucou**toi***";
	char **cc = ft_strsplit(d, '*');
	return (0);
}

