#include "fillit.h"


void	xy_figures(t_tetri **tetri, int x, int y)
{
	int	pos_x;
	int pos_y;
	int i;

	i = 0;
	pos_x = 15;
	pos_y = 15;
	while (i < 4)
	{
		if ((*tetri)->x[i] < pos_x)
			pos_x = (*tetri)->x[i];
		if ((*tetri)->y[i] < pos_y)
			pos_y = (*tetri)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*tetri)->x[i] = (*tetri)->x[i] - pos_x + x;
		(*tetri)->y[i] = (*tetri)->y[i] - pos_y + y;
		i--;
	}
}

char	**algorythm(char **tetri_map, t_tetri *tetri, int size)
{
	int		x;
	int		y;
	char	**map;

	if (tetri->next == NULL)
		return (tetri_map);
	map = NULL;
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			xy_figures(&tetri, x, y);
			if (check_figures(tetri_map, tetri, size))
				map = algorythm(insert_figures(tetri_map, tetri, size),
						tetri->next, size);
			if (map)
				return (map);
			tetri_map = fill_dotboard(tetri_map, tetri, size);
		}
	}
	return (NULL);
}

void	solve(t_tetri *tetri)
{
	char	**result;
	char	**tetri_map;
	int		size;

	size = 1;
	tetri_map = NULL;
	tetri_map = figures_map_new(tetri_map, size);
	result = NULL;
	while (!(result = algorythm(tetri_map, tetri, size)))
	{
		size++;
		ft_memdel((void **)tetri_map);
		tetri_map = figures_map_new(tetri_map, size);
	}
	print_map(result);
}
