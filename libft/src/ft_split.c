/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:46:17 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 10:40:24 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_wds(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (counter);
		counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

static void	*ft_free(char **arr, int elem)
{
	int	i;

	i = 0;
	while (i < elem)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	calc_leng(char const *str, int i, char c)
{
	int	leng;

	leng = 0;
	while (str[i] != c && str[i] != '\0')
	{
		leng++;
		i++;
	}
	return (leng);
}

char	**ft_split(char const *str, char c)
{
	int		a;
	int		i;
	char	**str_arr;

	a = 0;
	i = 0;
	str_arr = (char **)malloc(sizeof(char *) * (count_wds(str, c) + 1));
	if (str_arr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			str_arr[a] = ft_substr(str, i, calc_leng(str, i, c));
			if (str_arr[a] == NULL)
				return (ft_free(str_arr, a));
			a++;
			i = i + calc_leng(str, i, c);
		}
	}
	str_arr[a] = NULL;
	return (str_arr);
}
/*
int     main(void)
{
	int	i = 0;
    char *str = "ho li ";
    char    c = ' ';

    char **arr_words = ft_split(str,c);

	while (arr_words[i] != NULL)
	{
		printf("word: %s\n", arr_words[i]);
		i++;
	}
    return (0);
}*/
