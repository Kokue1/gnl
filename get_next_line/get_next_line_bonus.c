/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:02:35 by flemos-d          #+#    #+#             */
/*   Updated: 2021/03/03 13:11:01 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_write_line(t_list *struct_, char *main_string, char **line)
{
	char	*temp;

	temp = ft_strdup(main_string);
	temp[struct_->save_pos] = '\0';
	if (temp[0] == '\0')
		*line = ft_strdup("");
	else
		*line = ft_strdup(temp);
	free(temp);
}

static int	get_new_term(t_list *struct_, char *main_string)
{
	struct_->save_pos = 0;
	if (main_string[0] == '\0')
	{
		struct_->returnvalue = false;
		return (0);
	}
	while (main_string[struct_->save_pos])
	{
		if (main_string[struct_->save_pos] == '\n')
		{
			struct_->returnvalue = true;
			break ;
		}
		struct_->save_pos++;
		struct_->returnvalue = false;
	}
	return (struct_->save_pos);
}

static char	*save_line_cut_str(t_list *struct_, char *main_string, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	struct_->save_pos = get_new_term(struct_, main_string);
	ft_write_line(struct_, main_string, line);
	if (main_string[struct_->save_pos] == '\0')
	{
		free(main_string);
		main_string = NULL;
		return (main_string);
	}
	struct_->save_pos += 1;
	temp = malloc(sizeof(char ) * ft_strlen(main_string) + 1);
	if (!temp)
		return (NULL);
	while (main_string[struct_->save_pos])
	{
		temp[i] = main_string[struct_->save_pos];
		struct_->save_pos++;
		i++;
	}
	temp[i] = '\0';
	free(main_string);
	return (temp);
}

static char	*trade_main(t_list *struct_, char *main_string)
{
	char	*temp;

	struct_->buffer[struct_->ret] = '\0';
	if (!main_string)
		main_string = ft_strdup(struct_->buffer);
	else
	{
		temp = ft_strjoin(main_string, struct_->buffer);
		free(main_string);
		main_string = NULL;
		return (temp);
	}
	return (main_string);
}

int			get_next_line(int fd, char **line)
{
	static char	*main_string[MAX_SIZE];
	t_list		struct_;

	if (fd < 0 || fd == 1 || fd == 2 || line == NULL
		|| BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (-1);
	struct_.buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (struct_.buffer == NULL)
		return (-1);
	struct_.ret = read(fd, struct_.buffer, BUFFER_SIZE);
	main_string[fd] = trade_main(&struct_, main_string[fd]);
	while (struct_.ret && !ft_strchr(struct_.buffer, '\n'))
	{
		struct_.ret = read(fd, struct_.buffer, BUFFER_SIZE);
		main_string[fd] = trade_main(&struct_, main_string[fd]);
	}
	free(struct_.buffer);
	main_string[fd] = save_line_cut_str(&struct_, main_string[fd], line);
	if (struct_.returnvalue)
		return (1);
	return (0);
}
