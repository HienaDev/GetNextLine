/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-l <arocha-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:44:48 by arocha-l          #+#    #+#             */
/*   Updated: 2022/01/27 16:04:06 by arocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *prefix, char *right)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!prefix)
	{
		prefix = (char *)malloc(1 * sizeof(char));
		prefix[0] = '\0';
	}
	if (!prefix || !right)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(prefix) + ft_strlen(right)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (prefix)
		while (prefix[++i] != '\0')
			str[i] = prefix[i];
	while (right[j] != '\0')
		str[i++] = right[j++];
	str[ft_strlen(prefix) + ft_strlen(right)] = '\0';
	free(prefix);
	return (str);
}
