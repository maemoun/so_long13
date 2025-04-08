/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:03:42 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/08 11:06:39 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_len_sep(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	ft_word(const char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (w);
}

static void	ft_free_arr(char **arr, int index)
{
	while (index > 0)
	{
		index--;
		free(arr[index]);
	}
	free(arr);
}

static char	**ft_spwork(char **arr, char const *s, char c, int word)
{
	int	i;

	i = 0;
	while (i < word)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			arr[i] = ft_substr(s, 0, ft_len_sep(s, c));
			if (arr[i] == NULL)
			{
				ft_free_arr(arr, i);
				return (NULL);
			}
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;

	if (!s)
		return (NULL);
	word = ft_word(s, c);
	arr = malloc((word + 1) * 8);
	if (!arr)
		return (NULL);
	return (ft_spwork(arr, s, c, word));
}
