/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:36:39 by flemos-d          #+#    #+#             */
/*   Updated: 2021/01/27 13:00:27 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_has_line_break(char *trade)
{
	int count;

	count = 0;
	while (trade[count])
	{
		if (trade[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}

int		ft_get_line_break(char *trade)
{
	int count;

	count = 0;
	while (trade[count])
	{
		if (trade[count] == '\n')
			return (count + 1);
		count++;
	}
	return (count + 1);
}

char	*ft_trade(char *trade)
{
	int i;

	i = ft_get_line_break(trade);
	return (trade + i);
}

int		ft_verify(char *trade, char **line)
{
	if (!trade)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (!(*line = (char *)malloc(sizeof(char) *
	ft_strlen((const char *)trade) + 1)))
		return (-1);
	ft_strlcpy(*line, trade, ft_get_line_break(trade));
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char *trade[MAX_SIZE];
	t_list		list;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((list.i = read(fd, list.buffer, BUFFER_SIZE)) > 0)
	{
		list.buffer[list.i] = '\0';
		if (!trade[fd])
			trade[fd] = ft_strdup(list.buffer);
		else
			trade[fd] = ft_strjoin(trade[fd], list.buffer);
	}
	if (list.i < 0)
		return (-1);
	list.i = ft_verify(trade[fd], line);
	if (list.i == 0)
		return (0);
	if (ft_has_line_break(trade[fd]))
	{
		trade[fd] = ft_trade(trade[fd]);
		return (1);
	}
	trade[fd] = ft_trade(trade[fd]);
	return (0);
}
