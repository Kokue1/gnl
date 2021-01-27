/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:36:47 by flemos-d          #+#    #+#             */
/*   Updated: 2021/01/27 15:46:53 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# ifndef MAX_SIZE
#  define MAX_SIZE 4096
# endif

typedef struct		s_list
{
	int			i;
	char		buffer[BUFFER_SIZE + 1];
}					t_list;

int					get_next_line(int fd, char **line);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strchr(const char *haystack, int needle);

size_t				ft_strlen(const char *s);

char				*ft_strdup(const char *string);

char				*ft_substr(char const *s, unsigned int start, size_t len);

unsigned int		ft_strlcpy(char *dest, char *src, size_t size);

#endif
