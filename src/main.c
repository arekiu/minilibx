#include "fdf.h"


int	main(int argc, char *argv[])
{
	int	**coord_map;
	int	i;
	int j;
	int	splits;

	i = 0;
	if (argc != 2)
	{
		ft_printf("%s", "Invalid number of arguments");
		return (0);
	}

	int height = count_height(argv[1]);
    if (height == -1)
    {
        printf("Failed to open the map file\n");
        return 1;
    }

    coord_map = parse_map(argv[1]);
    if (coord_map == NULL)
    {
        printf("Failed to parse the map\n");
        return 1;
    }

    while (i < height)
	{
		j = 0;
		splits = 6;
		while (j < splits)
		{
			ft_printf("%d ", coord_map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}

    // Free the allocated memory
    for (int i = 0; i < height; i++)
        free(coord_map[i]);
    free(coord_map);

    return 0;

}
