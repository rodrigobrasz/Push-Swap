/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:13:43 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/22 23:54:09 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_freesplit(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

static char	*ft_fill_split(char const *str, char delim)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] != delim)
			i++;
		return (ft_substr(str, 0, i));
	}
	return (NULL);
}

static size_t	ft_count_words(const char *str, int delim)
{
	size_t	counter;
	size_t	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delim)
			i++;
		if (str[i] && str[i] != delim)
		{
			counter++;
			while (str[i] && str[i] != delim)
				i++;
		}
	}
	return (counter);
}

char	**ft_split(char const *str, char delim)
{
	char	**result;
	int		word_count;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	word_count = ft_count_words(str, delim);
	result = ft_calloc(word_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (++i < word_count)
	{
		while (str[j] && str[j] == delim)
			j++;
		result[i] = ft_fill_split(str + j, delim);
		if (!result)
			return (ft_freesplit(result), NULL);
		while (str[j] && str[j] != delim)
			j++;
	}
	result[i] = NULL;
	return (result);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*(str++) - '0');
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (INT_MAX + 1L);
	}
	return (result * sign);
}
