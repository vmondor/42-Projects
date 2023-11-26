/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:24:17 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/22 18:11:56 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static int	ft_allocate(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_strings(char *str, char c, char **strings, int string_index)
{
	int	i;
	int	j;

	i = 0;
	while (string_index < ft_nb_words(str, c))
	{
		while (str[i] == c)
			i++;
		strings[string_index] = (char *)ft_calloc(sizeof(char),
				(ft_allocate(&str[i], c) + 1));
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

char	**ft_split(char const *s, char c)
{
	char	**strings;
	char	*str;
	int		string_index;
	int		nb_words;

	str = (char *)s;
	nb_words = ft_nb_words(str, c);
	strings = (char **)ft_calloc(sizeof(char *), (nb_words + 1));
	if (!s || !strings)
		return (NULL);
	string_index = 0;
	return (ft_strings(str, c, strings, string_index));
}
