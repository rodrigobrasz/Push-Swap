/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:13:43 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/27 00:09:28 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(const char *s, char c)
{
	int	word_c;
	int	x;

	word_c = 0;
	x = 0;
	while (s[x])
	{
		if (s[x] != c)
		{
			word_c += 1;
			while (s[x] && s[x] != c)
				x++;
			continue ;
		}
		x++;
	}
	return (word_c);
}

static char	*words(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	*words;

	words = NULL;
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	words = malloc(sizeof(char) * (i + 1));
	if (words == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		words[j] = s[j];
		j++;
	}
	words[j] = '\0';
	return (words);
}

static char	**split(const char *s, char c, char **dest)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s[x])
	{
		if (s[x] != c)
		{
			dest[y] = words(&s[x], c);
			if (dest[y] == NULL)
			{
				while (--y >= 0)
					free(dest[y]);
				free(dest);
				return (NULL);
			}
			y++;
			while (s[x] && s[x] != c)
				x++;
			continue ;
		}
		x++;
	}
	return (dest);
}

char	**ft_split(char *s, char c)
{
	size_t	wcount;
	char	**dest;

	if (!s)
		return (NULL);
	wcount = word_count(s, c);
	dest = malloc(sizeof(char *) * (wcount + 1));
	if (dest == NULL)
		return (NULL);
	dest[wcount] = NULL;
	dest = split(s, c, dest);
	return (dest);
}
