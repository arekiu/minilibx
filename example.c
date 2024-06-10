#include <mlx.h>
#include "./libft/src/libft.h"

void	*convert_map(void)
{
	int	fd;
	char	*line;

	fd = open("line.fdf", O_RDONLY);
	line = get_next_line(fd);
	close(fd);
	printf("%s", line);
	//free(line);
	return (line);
}

int	main(void)
{
	convert_map();
}

