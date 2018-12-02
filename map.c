#include "fillit.h"

char	**figures_map_new(char **map, int size)
{
	int x;
	int y;

	y = -1;
	_ERR_NOTIS((map = (char **)malloc(sizeof(char *) * size + 1)));
	while (++y < size)
	{
		_ERR_NOTIS((map[y] = (char *)malloc(sizeof(char) * size + 1)));
		x = -1;
		while (++x < size)
			map[y][x] = '.';
		map[y][x] = '\0';
	}
	map[y] = 0;
	return (map);
}


char	**fill_dotboard(char **map, t_tetri *tetri, int size)
{
	int x;
	int y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (map[y][x] == tetri->c)
				map[y][x] = '.';
		}
	}
	return (map);
}

char	**insert_figures(char **map, t_tetri *tetri, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (tetri->y[i] == y && tetri->x[i] == x)
			{
				map[y][x] = tetri->c;
				i++;
			}
		}
	}
	return (map);
}

void	print_map(char **map)
{
	int i;

		if (map == NULL)
		{
			ft_putendl("error");
			return ;
		}
	i = 0;
	while (map[i] != 0)
	{
		ft_putendl(map[i]);
		i++;
	}
}
