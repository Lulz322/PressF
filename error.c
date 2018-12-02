#include "fillit.h"


int		validate_box(char *str, int i)
{
	int hash;
	int j;
	int x;

	hash = 0;
	x = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[x] != '.' && str[x] != '#')
				return (-1);
			if (str[x] == '#')
				hash++;
			x++;
			j++;
		}
		if (str[x] == '\n')
			x++;
		i++;
	}
	if (hash != 4 || (str[x] != '\n' && str[x] != '\0'))
		return (-1);
	return (x);
}

bool	ft_validate(char *str)
{
	int i;
	int j;
	int count;

	count = 0;
	j = 0;
	i = 0;
	while (1)
	{
		j = validate_box(&str[i], 0);
		if (j == -1)
      return (false);
		i += j;
		count++;
		if (str[i] == '\0')
			break ;
		else if (str[i] == '\n')
			i++;
	}
	g_count = count;
	return (true);
}
