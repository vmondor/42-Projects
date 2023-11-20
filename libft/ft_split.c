/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:24:17 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/20 17:00:46 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		a;
	int		i;
	int		j;
	int		t;
	int		ri;

	i = 0;
	j = 0;
	a = 0;
	ri = 0;
	tab = NULL;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (j > 0)
				a = i - (int)ft_strlen(tab[j-1]);
			else
				a = i + 1;
			tab[j] = malloc(sizeof(char) * a);
			t = 0;
			ri = a - i - 1;
			while (s[ri] != c)
			{
				tab[j][t] = s[ri];
				ri++;
				t++;
			}
			tab[j][t] = '\0';
			j++;
		}
		i++;
	}
	return (tab);
}

/*
int	main(void)
{
	char	s[] = "Valentin,Fabiola,Annick,Jacques";
	char	**tab;
	int		i;

	tab = ft_split(s, ',');
	i = 0;
	while(tab[i])
	{
		printf("%d\t: %s\n", i, tab[i]);
		i++;
	}
	return (0);
}*/