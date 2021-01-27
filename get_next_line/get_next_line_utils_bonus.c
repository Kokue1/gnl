/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemos-d <flemos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:24:51 by flemos-d          #+#    #+#             */
/*   Updated: 2021/01/21 19:54:17 by flemos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char				*ft_strdup(const char *string)
{
	char	*trade;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen((char *)string);
	if (!(trade = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (string[i])
	{
		trade[i] = string[i];
		i++;
	}
	trade[i] = '\0';
	return (trade);
}

unsigned int		ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	if (!dest || !src)
		return (0);
	len = ft_strlen(src);
	if (!size)
		return (len);
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

size_t				ft_strlen(const char *s)
{
	int i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*trade;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!s2 && s1)
		return ((char *)s1);
	k = ft_strlen(s1) + ft_strlen(s2);
	if (!(trade = malloc(k + 1 * sizeof(trade))))
		return (NULL);
	while (s1[i] != '\0')
	{
		trade[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		trade[i++] = s2[j++];
	trade[i] = '\0';
	return (trade);
}
