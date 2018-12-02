#ifndef FILLIT_H
# define FILLIT_H
# include "libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


enum	e_bool
{
	false = 0,
	true
};
# define _ERR_NOTIS(ex) if (!(ex)) return (NULL)
# define _ERR_NOTIS_MSG(ex) if (!(ex)) { _ERR_MSG("error"); return (false); }
# define _ERR_MSG(msg) ft_putendl(msg)
# define _BOOL	typedef enum e_bool bool

_BOOL;

typedef struct		s_tetri
{
	char			c;
	int				x[4];
	int				y[4];
	struct s_tetri	*next;
}					t_tetri;
int	g_count;
bool	ft_validate(char *str);
int		validate_box(char *str, int i);
int					count_figures(char *str);
void				set_figures(t_tetri **tmp, char *str);
t_tetri				*buff_figures(char *str);
char				*buff_str(int fd);
void				xy_figures(t_tetri **tetri, int x, int y);
char				**algorythm(char **tetri_map, t_tetri *tetri, int size);
void				solve(t_tetri *tetri);
char				**figures_map_new(char **map, int size);
void				print_map(char **map);
char				**fill_dotboard(char **map, t_tetri *tetri, int size);
char				**insert_figures(char **map, t_tetri *tetri, int size);
int					check_links(char *stock, int j);
int					check_hashteck(char *stock, int j);
int					check_str(char *stock);
int					check_figures(char **map, t_tetri *tetri, int size);

#endif
