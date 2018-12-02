#include "fillit.h"

int		check_links(char *stock, int j)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (stock[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && stock[i + j + 1] == '#')
				count++;
			if ((i + j - 1) >= (0 + j) && stock[i + j - 1] == '#')
				count++;
			if ((i + j + 5) < (20 + j) && stock[i + j + 5] == '#')
				count++;
			if ((i + j - 5) >= (0 + j) && stock[i + j - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		check_hashteck(char *stock, int j)
{
	int hash;
	int dot;
	int n;
	int i;

	i = 0;
	hash = 0;
	dot = 0;
	n = 0;
	while (i + j < 20 + j && stock[i + j] != '\0')
	{
		if (stock[i + j] == '.')
			dot++;
		if (stock[i + j] == '#')
			hash++;
		if (stock[i + j] == '\n')
			n++;
		i++;
	}
	if (hash == 4 && dot == 12 && n == 4)
		return (1);
	return (0);
}

int		check_figures(char **map, t_tetri *tetri, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (tetri->y[i] < size && tetri->x[i] < size &&
				map[tetri->y[i]][tetri->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
		}
	}
	return (0);
}

int			count_figures(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			result++;
		i++;
	}
	result = result / 4;
	return (result);
}
