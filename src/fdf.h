#ifndef FDF_H
# define FDF_H

#include "../libft/src/libft.h"
#include <mlx.h>

int		**parse_map(char	*map_name);
int		count_height(char *map_name);
void	fill_line(char *line, int **parsed_map);

#endif



