#include "fdf.h"

int	count_height(char *map_name)
{
	int	fd;
	int	i;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
        return (-1);
	line = get_next_line(fd);
	while (line != NULL)
    {
        i++;
        free(line);
		line = get_next_line(fd);
    }
	close(fd);
	return (i);
}


static int	count_splits(char **num_arr)
{
	int	i;

	i = 0;
	while(num_arr[i] != NULL)
		i++;
	return (i);
}

void	fill_line(char *line, int **parsed_map)
{
	char	**num_arr;
	int		i;
	int		*arr_of_ints;

	i = 0;
	num_arr = ft_split(line, ' ');
	if (!num_arr)
        return;
	arr_of_ints = malloc(sizeof(int) * count_splits(num_arr));
	if (!arr_of_ints)
		return;
	while (num_arr[i] != NULL)
	{
		arr_of_ints[i] = ft_atoi(num_arr[i]);
		free(num_arr[i]);
		i++;
	}
	*parsed_map = arr_of_ints;
	free (num_arr);
}
static void	read_map(char *map_name, int height, int **parsed_map)
{
	int	i;
	int	fd;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
    if (fd < 0)
    {
        free(parsed_map);
        return;
    }
	while (i < height)
	{
		line = get_next_line(fd);
        if (line == NULL)
        {
            free(parsed_map);
            close(fd);
            return;
        }
        fill_line(line, &parsed_map[i]);
        free(line);
		i++;
	}
	close(fd);
}

int	**parse_map(char *map_name)
{
	int		height;
	int		**parsed_map;
	int		i;

	i = 0;
	height = count_height(map_name);
	if (height == -1)
		return (NULL);
	parsed_map = malloc(sizeof(int *) * height);
	if (!parsed_map)
		return (NULL);
	read_map(map_name, height, parsed_map);
	return (parsed_map);
}

