/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:02:35 by flemos-d          #+#    #+#             */
/*   Updated: 2021/02/09 17:04:09 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	srch_break(char *search)
{
	int	i;

	i = 0;
	if (!search)
		return (0);
	while (search[i])
	{
		if (search[i] == '\n')
			return (i = 1);
		i++;
	}
	return (0);
}

char	*remove_after_line_break(char *final)
{
	int		i;
	int		a;
	char	*temp;

	a = 0;
	i = get_line_break(final) + 1;
	temp = malloc((ft_strlen(final) + 1 - i) * sizeof(char));
	if (!temp)
		return (NULL);
	while (final[i] != '\0')
	{
		temp[a] = final[i];
		i++;
		a++;
	}
	temp[a] = '\0';
	free(final);
	return (temp);
}

char	*new_line_return(char *file_content, char **ret)
{
	int		linebreak;
	char	*temp;

	linebreak = get_line_break(file_content);
	temp = ft_strdup(file_content);
	temp[linebreak] = '\0';
	*ret = ft_strdup(temp);
	if (srch_break(file_content))
		file_content = remove_after_line_break(file_content);
	else
	{
		free(file_content);
		file_content = ft_strdup("");
	}
	free(temp);
	return (file_content);
}

int	ret_func(char **f_content, char **line)
{
	char	*ptr;

	ptr = *f_content;
	if (ptr[0] == '\0'
		|| ptr[get_line_break(ptr)] == '\0')
	{
		*f_content = new_line_return(ptr, line);
		return (0);
	}
	*f_content = new_line_return(ptr, line);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*f_content[255];
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 2) * sizeof(char));
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || !buffer)
		return (-1);
	if (!srch_break(f_content[fd]))
	{
		if (!f_content[fd])
			f_content[fd] = ft_strdup("");
		ret = 1;
		while (ret > 0)
		{
			ret = read(fd, buffer, BUFFER_SIZE);
			buffer[ret] = '\0';
			f_content[fd] = ft_strjoin(f_content[fd], buffer);
			if (srch_break(f_content[fd]))
				break ;
		}
		free(buffer);
		if (ret < 0)
			return (ret_invalid(line));
	}
	return (ret_func(&f_content[fd], line));
}
