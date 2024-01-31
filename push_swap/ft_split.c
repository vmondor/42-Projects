/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:45:43 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/29 15:12:00 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_nb_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static int	ft_allocate(char const *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_strings(char *str, char c, char **strings,
								int string_index)
{
	int	i;
	int	j;

	i = 0;
	while (string_index < ft_nb_words(str, c))
	{
		while (str[i] == c)
			i++;
		strings[string_index] = (char *)malloc(sizeof(char)
				* (ft_allocate(&str[i], c) + 1));
		if (!strings[string_index])
			return (NULL);
		j = 0;
		while (str[i] && str[i] != c)
		{
			strings[string_index][j] = str[i];
			i++;
			j++;
		}
		strings[string_index][j] = '\0';
		string_index++;
	}
	return (strings[string_index] = NULL, strings);
}

char	**ft_split(char *str, char c)
{
	char	**strings;
	int		string_index;
	int		nb_words;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] <= ' ')
		i++;
	nb_words = ft_nb_words(str + i, c);
	strings = malloc(sizeof(char *) * (nb_words + 1));
	if (!strings)
		return (NULL);
	string_index = 0;
	return (ft_strings(str, c, strings, string_index));
}
