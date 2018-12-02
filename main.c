#include "fillit.h"

int			main(int argc, char **argv)
{
	char	*buff;
	int		fd;
	t_tetri	*figure;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit *FILE_NAME*");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	buff = buff_str(fd);
	if (!ft_validate(buff))
	{
		ft_putendl("error");
		return (0);
	}
	_ERR_NOTIS(figure = buff_figures(buff));
	solve(figure);
	free(figure);
	free(buff);
	close(fd);
	return (0);
}
