/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:28:47 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/22 13:04:45 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *s);
int		ft_strchr(char *s, char c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif