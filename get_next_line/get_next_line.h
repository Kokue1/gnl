/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:02:47 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/10 21:04:14 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_SIZE
#  define MAX_SIZE 4096
# endif

typedef struct s_list
{
	char	*buffer;
	int		nullterminator;
	int		ret;
	int		save_pos;
	int		linebreak;
	bool	returnvalue;
}					t_list;

int			get_next_line(int fd, char **line);

size_t		ft_strlen(const char *s);

char		*ft_strjoin(char *s1, char const *s2);

char		*ft_strdup(const char *s);

char		*ft_strchr(const char *haystack, int needle);

#endif
