#include "fillit.h"

void		set_figures(t_tetri **tmp, char *str)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			++j;
		}
	}
}

t_tetri		*buff_figures(char *str)
{
	int		c_tetri;
	int		add21;
	char	c;
	t_tetri *stock;
	t_tetri *tmp;

	add21 = 0;
	c = 'A';
	c_tetri = count_figures(str);
	_ERR_NOTIS((stock = (t_tetri *)malloc(sizeof(t_tetri))));
	tmp = stock;
	while (c_tetri > 0)
	{
		tmp->c = c;
		set_figures(&tmp, ft_strsub(str, 0 + add21, 20));
		_ERR_NOTIS(tmp->next = (t_tetri *)malloc(sizeof(t_tetri)));
		tmp = tmp->next;
		c_tetri--;
		c++;
		add21 += 21;
	}
	tmp->next = NULL;
	return (stock);
}

char		*buff_str(int fd)
{
	int		f;
	int		i;
	char	c;
	char	*str;

	i = 0;
	f = read(fd, &c, 1);
	if (f < 0)
		return (NULL);
	if (f == 1)
	{
		_ERR_NOTIS(str = (char *)malloc(sizeof(char) * 550));
		while (f)
		{
			str[i] = c;
			i++;
			f = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	return (str);
}
