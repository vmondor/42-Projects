/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:29:02 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/17 18:19:49 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Liste *initialisation()
{
    t_Liste *t_liste = malloc(sizeof(*t_liste));
    t_list *element = malloc(sizeof(*element));

    if (t_liste == NULL || element == NULL)
    {
        return (NULL);
    }
    element->nb = 0;
    element->next = NULL;
    t_liste->first = element;

    return t_liste;
}

void insertion(t_Liste *t_liste, int nvNombre)
{
    /* Création du nouvel élément */
    t_list *nouveau = malloc(sizeof(*nouveau));
    if (t_liste == NULL || nouveau == NULL)
    {
        return ;
    }
    nouveau->nb = nvNombre;

    /* Insertion de l'élément au début de la t_liste */
    nouveau->next = t_liste->first;
    t_liste->first = nouveau;
}

int	main(int ac, char **av)
{
    int i;
	t_Liste	*t_liste;
    
	t_liste = initialisation();
    i = 0;
    while (i < ac - 1)
    {
        insertion(t_liste, ft_atoi(av[i]));
        i++;
    }
    // insertion(t_liste, 4);
    // insertion(t_liste, 6);
    // insertion(t_liste, 54);
    // insertion(t_liste, 65);


	t_list *actuel = t_liste->first;

    while (actuel)
    {
        printf("%d\n", actuel->nb);
        actuel = actuel->next;
    }
	return (0);
}
